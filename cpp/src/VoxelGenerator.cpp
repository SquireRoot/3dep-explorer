/** Contains algorithms written in cpp that are used by 3dep_explorer.ipynb
 * 
 * \author Evan Newman (evanmnewman1@gmail.com)
 * \date Dec 2023
*/

#include <limits>
#include <vector>

#include <Eigen/Core>

#include "VoxelGenerator.h"

Eigen::MatrixXd lidar_voxelize(const Eigen::Ref<Eigen::MatrixXd, 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> points, 
                               double voxel_size) {

    // voxel grid origin is minimum x, y, and z of all points
    Eigen::MatrixXd voxel_grid_origin = points.colwise().minCoeff();

    // // voxel gird size is the number of voxels, number of z voxels is unused
    Eigen::MatrixXi voxel_grid_size = 
        ((points.colwise().maxCoeff() - voxel_grid_origin)/voxel_size).array().ceil().cast<int>();

    // std::cout << "voxel_grid_origin is: " << std::endl << voxel_grid_origin << std::endl;
    // std::cout << "voxel_grid_size is " << std::endl << voxel_grid_size << std::endl;

    // // unordered multimap to associate a voxel index to a set of lidar points
    std::vector<std::vector<Eigen::MatrixXd>> point_bins(voxel_grid_size(0, 0)*voxel_grid_size(0, 1));

    // iterate through all the lindar points in points
    for (int64_t i = 0; i < points.rows(); i++) {
        // std::cout << "point is: " << std::endl << points.row(i) << std::endl;

        // get the index of the voxel which should contain the point
        Eigen::MatrixXi voxel_idx = ((points.row(i) - voxel_grid_origin)/voxel_size).cast<int>();
        // std::cout << "voxel_index is: " << std::endl << voxel_idx << std::endl;

        // linear index as key so we don't have to define some new key type
        size_t voxel_linear_idx = voxel_idx(0, 0) + voxel_grid_size(0, 0)*voxel_idx(0, 1);

        // insert the point into the appropriate voxel index
        point_bins.at(voxel_linear_idx).push_back(points.row(i));
    }

    // return_val has at most the same number of points as cells in the voxel grid
    Eigen::MatrixXd return_val(voxel_grid_size(0, 0)*voxel_grid_size(0, 1), 3);

    // counter to store the current voxel pt we are working on,
    size_t voxel_out_idx = 0; 

    for (int y = 0; y < voxel_grid_size(1); y++) {
        for (int x = 0; x < voxel_grid_size(0); x++) {
            size_t voxel_linear_idx = x + voxel_grid_size(0)*y;

            if (point_bins.at(voxel_linear_idx).size() < 1) {
                continue;
            }

            double voxel_elevation = std::numeric_limits<double>::max();

            for (Eigen::MatrixXd& point : point_bins.at(voxel_linear_idx)) {
                if (point(0, 2) < voxel_elevation) {
                    voxel_elevation = point(0, 2);
                }
            }

            return_val(voxel_out_idx, 0) = (x + 0.5)*voxel_size;
            return_val(voxel_out_idx, 1) = (y + 0.5)*voxel_size;
            return_val(voxel_out_idx, 2) = voxel_elevation;

            voxel_out_idx++;
        }
    }

    return return_val.block(0, 0, voxel_out_idx, 3);

}
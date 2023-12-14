/** Contains algorithms written in cpp that are used by 3dep_explorer.ipynb
 * 
 * \author Evan Newman (evanmnewman1@gmail.com)
 * \date Dec 2023
*/

// standard library
#include <iostream>

// catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <Eigen/Core>

// local 
#include "VoxelGenerator.h" 

TEST_CASE("Hello World") {
    int num_points = 10;
    Eigen::MatrixXd points(num_points, 3);

    for (int i = 0; i < num_points; i++) {
        points(i, 0) = 20.0*(static_cast<double>(std::rand())/RAND_MAX);
        points(i, 1) = 20.0*(static_cast<double>(std::rand())/RAND_MAX);
        points(i, 2) = 1.0*(static_cast<double>(std::rand())/RAND_MAX);
    }

    Eigen::MatrixXd voxel_points = lidar_voxelize(points, 1.0);
}
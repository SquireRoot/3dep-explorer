/** Contains algorithms written in cpp that are used by 3dep_explorer.ipynb
 * 
 * \author Evan Newman (evanmnewman1@gmail.com)
 * \date Dec 2023
*/

#ifndef VOXEL_GENERATOR_H
#define VOXEL_GENERATOR_H

#include <iostream>

#include <Eigen/Core>

/** filters a set of lidar points to remove partially transparent ground based clutter like trees and bushes
 * 
 * \param[in] points the (Nx3) set of points to filter
*/
Eigen::MatrixXd lidar_voxelize(const Eigen::Ref<Eigen::MatrixXd, 0, Eigen::Stride<Eigen::Dynamic, Eigen::Dynamic>> pointspoints, 
                               double voxel_size);

#endif
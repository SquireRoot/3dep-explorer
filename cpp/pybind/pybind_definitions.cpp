/** Contains algorithms written in cpp that are used by 3dep_explorer.ipynb
 * 
 * \author Evan Newman (evanmnewman1@gmail.com)
 * \date Dec 2023
*/

// system includes
#include <iostream>
#include <unordered_map>
#include <tuple>

// pybind11 includes
#include <pybind11/pybind11.h>
#include <pybind11/eigen/matrix.h>
#include <pybind11/stl.h>

#include "VoxelGenerator.h"

PYBIND11_MODULE(cpphelpers, m) {
    m.doc() = "Algorithms for lidar filtering"; // optional module docstring

    m.def("lidar_voxelize", &lidar_voxelize,
          pybind11::arg("points"), pybind11::arg("voxel_size"));
}
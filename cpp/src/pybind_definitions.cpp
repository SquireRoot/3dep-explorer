#include <pybind11/pybind11.h>
#include <pybind11/eigen/matrix.h>
#include <pybind11/stl.h>

int add(int i, int j) {
    return i + j;
}



PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");

        // test_named_arguments
    // Make sure named arguments are working properly:
    m.def(
        "matrix_multiply",
        [](const py::EigenDRef<const Eigen::MatrixXd> &A,
           const py::EigenDRef<const Eigen::MatrixXd> &B) -> Eigen::MatrixXd {
            if (A.cols() != B.rows()) {
                throw std::domain_error("Nonconformable matrices!");
            }
            return A.array() * B.array();
        },
        py::arg("A"),
        py::arg("B"));
}
#!/bin/bash

echo Building

g++ -O3 -Wall -shared -std=c++11 -fPIC \
    $(python3 -m pybind11 --includes) -Icpp/src \
    cpp/src/pybind_definitions.cpp \
    -o cpp/3dep_explorer$(python3-config --extension-suffix) 
#!/bin/bash

# git submodule init
# git submodule update
# python3 -m venv .venv
# source .venv/bin/activate
# pip install -r requirements.txt

g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) src/filter.cpp -o example$(python3-config --extension-suffix)
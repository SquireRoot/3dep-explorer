# 3dep-explorer
## Building and running

### Get the git submodules 
    git submodule init
    git submodule update

### Set up a python virtual environment and install the dependencies
    python3 -m venv .venv
    source .venv/bin/activate
    pip install -r requirements.txt

### Build the cpp side of the project
    mkdir build/ # python will expect this directory to be named build
    cd build/
    cmake ..
    make

### Run the cpp side unit tests (optional)
    ./build/tests

### Running 3dep_explorer.ipynb

1. Visit https://apps.nationalmap.gov/lidar-explorer/#/
2. Select the area you would like to download
3. On the right pane, under Downloadable Products Within AOI/Lidar within AOI, click the button to the right of Lidar Point Cloud (LPC) to get the download list
4. Put the downloadlist.txt file into the root directory of this project and replace the default one
5. Open the notebook in your program of choice and run all cells



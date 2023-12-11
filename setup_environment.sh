#!/bin/bash

git submodule init
git submodule update
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
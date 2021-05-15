#!/bin/bash

mkdir -p src
touch src/README.md

mkdir -p input
touch input/README.md

mkdir -p config
touch input/README.md

mkdir -p output
touch output/README.md

[ ! -f "CMakeLists.txt" ] && > CMakeLists.txt

[ ! -f "build.sh" ] && > build.sh

[ ! -f "run.sh" ] && > run.sh

cd src

touch std_inc.h
touch io_inc.h
touch open_3rd_inc.h
touch main.cpp
touch CMakeLists.txt

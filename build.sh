#!/bin/sh

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
cp exp2svg/Expression2SVG ..

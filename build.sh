#!/bin/bash

rm -rf build
mkdir -p build
cd build
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..
cd ..
ninja -C build

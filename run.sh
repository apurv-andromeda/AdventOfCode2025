#!/usr/bin/zsh

rm -rf build 
mkdir build

cd build

cmake ..

make

cd ..
./build/AdventOfCode2025

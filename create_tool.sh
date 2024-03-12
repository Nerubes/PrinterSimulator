#!/bin/bash

rm -r build

cmake -S. -Bbuild
cd build
make imgen

mv imgen ../console_tool/

cd ../console_tool

./imgen image test_dir config.cf

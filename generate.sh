#!/bin/bash

rm -r build

cmake -S. -Bbuild
cd build
make Generate
./Generate

mv first_m.jpg ../example/imgs_modified/
mv second_m.jpg ../example/imgs_modified/
mv third_m.jpg ../example/imgs_modified/
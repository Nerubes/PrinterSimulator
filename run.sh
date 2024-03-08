#!/bin/bash

rm -r build

cmake -S. -Bbuild
cd build
make
./Application ../qr.jpg
mv result.jpg ..

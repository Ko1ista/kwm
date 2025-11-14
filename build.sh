#!/bin/bash
mkdir -p dist
cd dist
cmake "$@" ..
make -j$(nproc)
./kwm

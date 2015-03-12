#!/bin/bash

if [[ $(uname) == 'Darwin' ]]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

echo "building library..."
set -o verbose

c++ factorial.cpp -Wall --std=c++1y -fpic -shared -o $LIB

set +o verbose
echo "...done!"

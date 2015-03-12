#!/bin/bash

echo "building library..."
set -o verbose

c++ factorial.cpp -Wall --std=c++1y -fpic -shared -o libfactorial.so

set +o verbose
echo "...done!"

#!/bin/bash

set -o errexit

set -o verbose

echo "building application..."
c++ app.cpp -Wall --std=c++1y -o app -I../lib -L../lib -Wl,-rpath='$ORIGIN/../lib' -lfactorial
echo "...done!"

set +o verbose

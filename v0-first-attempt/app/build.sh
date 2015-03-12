#!/bin/bash

set -o errexit

echo "building application..."
set -o verbose
c++ app.cpp -Wall --std=c++1y -o app -I../lib -L../lib -Wl,-rpath='$ORIGIN/../lib' -lfactorial
set +o verbose
echo "...done!"


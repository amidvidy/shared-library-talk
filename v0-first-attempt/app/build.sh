#!/bin/bash

set -o errexit

if [[ $(uname) == 'Darwin' ]]; then
    export DYLD_LIBRARY_PATH=../lib
else
    export LD_LIBRARY_PATH=../lib
fi

set -o verbose

echo "building application..."
c++ app.cpp -Wall --std=c++1y -o app -I../lib -L../lib -lfactorial
echo "...done!"

set +o verbose

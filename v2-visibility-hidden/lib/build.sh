#!/bin/bash

export BASENAME="libfactorial.so"

export FACTORIAL_API_MAJOR=0
export FACTORIAL_API_MINOR=1
export FACTORIAL_API_PATCH=0

export FACTORIAL_ABI_VERSION=1

export FACTORIAL_PHYSICAL_NAME="$BASENAME.$FACTORIAL_API_MAJOR.$FACTORIAL_API_MINOR.$FACTORIAL_API_PATCH"
export FACTORIAL_SONAME="$BASENAME.$FACTORIAL_ABI_VERSION"

rm $BASENAME*

echo "building library..."
echo "filename is $FACTORIAL_PHYSICAL_NAME"
echo "soname is $FACTORIAL_SONAME"
set -o verbose

c++ factorial.cpp -Wall --std=c++1y -fvisibility=hidden -fpic -shared -Wl,-soname,$FACTORIAL_SONAME -o $FACTORIAL_PHYSICAL_NAME
ln -s $FACTORIAL_PHYSICAL_NAME $FACTORIAL_SONAME
ln -s $FACTORIAL_PHYSICAL_NAME $BASENAME

set +o verbose
echo "...done!"

set -o verbose
c++ --std=c++11 -c factorial.cpp
c++ factorial.o -shared -o libfactorial.dylib

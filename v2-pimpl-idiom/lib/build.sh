if [[ $(uname) == 'Darwin' ]]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

echo "building library..."

set -o verbose
c++ --std=c++11 -fvisibility=hidden -c factorial.cpp
c++ factorial.o -fvisibility=hidden -shared -o libfactorial.dylib
set +o verbose

echo "...done!"

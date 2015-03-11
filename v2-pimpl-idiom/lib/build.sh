if [[ $(uname) == 'Darwin' ]]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

echo "building library..."

set -o verbose
c++ -Wall --std=c++1y -fvisibility=hidden -c factorial.cpp
c++ --std=c++1y factorial.o -fvisibility=hidden -shared -o $LIB
set +o verbose

echo "...done!"

if [[ $(uname) == 'Darwin' ]]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

echo "building library..."

set -o verbose
c++ --std=c++1y -g -Wall -fvisibility=hidden -c factorial.cpp
c++ factorial.o -g -Wall -fvisibility=hidden -shared -o $LIB
set +o verbose

echo "...done!"

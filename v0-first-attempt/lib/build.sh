if [[ $(uname) == 'Darwin']]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

set -o verbose

echo "building library..."
c++ --std=c++11 -c factorial.cpp
c++ factorial.o -shared -o libfactorial.dylib
echo "...done!"

set +o verbose

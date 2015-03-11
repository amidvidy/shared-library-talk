if [[ $(uname) == 'Darwin' ]]; then
    LIB='libfactorial.dylib'
else
    LIB='libfactorial.so'
fi

echo "building library..."
set -o verbose
c++ -Wall --std=c++1y -c factorial.cpp
c++ factorial.o -shared -o $LIB
set +o verbose
echo "...done!"

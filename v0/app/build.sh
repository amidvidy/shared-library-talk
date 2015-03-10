set -o verbose
if [[ $(uname) == 'Darwin' ]]; then
    export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
else
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
fi
    
c++ main.cpp --std=c++1y -o main -I../lib -L../lib -lfactorial

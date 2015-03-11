if [[ $(uname) == 'Darwin' ]]; then
    export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
else
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
fi
set -o verbose
c++ -Wall app.cpp --std=c++1y -Wall -o app -I../lib -L../lib -lfactorial
set +o verbose

#!/bin/sh -e
set -v

export CXX=$(which g++)

cmake .

make

#make test

doxygen doc/dox 

unset CXX

set +v

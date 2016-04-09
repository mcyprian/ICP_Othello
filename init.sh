#!/bin/sh -e
set -v

export CXX=$(which g++)

cmake .

make

#make test

#idoxygen dox 1>/dev/null 2>/dev/null

unset CXX

set +v

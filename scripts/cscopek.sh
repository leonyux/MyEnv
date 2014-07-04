#!/bin/bash

MPWD=`pwd`

if [ $1 ]; then
    rm -rf cscope
    mkdir cscope
    find ${MPWD}/linux/ -regex ".*\.c*[chSsx]" > cscope/cscope.files
    cd cscope
    cscope -bkq
    cd ${MPWD}
fi

CSCOPE_DB=${MPWD}/cscope/cscope.out
export CSCOPE_DB


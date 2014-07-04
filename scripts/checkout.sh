#!/bin/env bash

if [ $1 ]; then
    cvs co -r $1 FDDBBU/1Develope_Case/HX-BPU_R3/
else
    cvs co FDDBBU/1Develope_Case/HX-BPU_R3/
fi

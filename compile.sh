#!/usr/bin/env bash

#qmake-qt5 -o Makefile vkeybd-qt.pro
qmake6 -o Makefile vkeybd-qt.pro

os=$(uname -s)

if [[ "$os" == "Linux" ]]; then
    make -j $(nproc)

    if [ $? -eq 0 ]
    then
        ./debug/vkeybd-qt
    fi
elif [[ "$os" == "Darwin" ]]; then
    make -j $(sysctl -n hw.logicalcpu)

    if [ $? -eq 0 ]
    then
        ./debug/vkeybd-qt.app/Contents/MacOS/vkeybd-qt
    fi
else
    echo "not supported, Compilation currently only works on MacOS and Linux"
    exit 1
fi

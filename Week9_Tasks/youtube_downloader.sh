#!/bin/bash

if ! [ -x "$(command -v youtube-dl)" ]; then
    echo "Youtube-dl is not installed"
    exit 1
fi

if [ $# -eq 0 ]; then 

    echo "please enter the youtube link as an argument"
    exit 1 
fi

youtube-dl "$1"
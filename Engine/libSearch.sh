#!/bin/sh

# $1 search e.g. XOpenDisplay

if [ -z $1 ]; then
    echo "Nothing to search"
else
    for A in $(ls /usr/lib/i386-linux-gnu/ | grep X); do 
        echo $A; nm -D "/usr/lib/i386-linux-gnu/${A}" | grep $1; 
    done
fi
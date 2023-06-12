#!/bin/bash
wget -P .. https://raw.githubusercontent.com/EseVic/alx-low_level_programming/master/0x18-dynamic_libraries/treatment.so
export LD_PRELOAD="$PWD/../treatment.so"

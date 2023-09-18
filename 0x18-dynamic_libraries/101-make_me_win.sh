#!/bin/bash
wget -P /tmp https://github.com/iyad-m-mahrous/alx-low_level_programming/blob/1a41d04399e93ba7046942d79a4fc22c49cd35d0/0x18-dynamic_libraries/win.so
export LD_PRELOAD=/tmp/win.so

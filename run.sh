#!/bin/bash

rm -rf build

# 3. Configure manually with explicit path
cmake -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug

# 4. Build
cmake --build build

# 5. Run
./build/bin/Debug-Darwin-arm64/Sandbox/Sandbox
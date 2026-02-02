#!/bin/bash

# Generate Makefiles using premake
vendor/bin/premake/premake5 gmake2

# Build the project
make config=debug

# Run the Sandbox application
./bin/Debug-macosx-AARCH64/Sandbox/Sandbox
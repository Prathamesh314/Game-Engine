# Clean everything
make clean
rm -rf *.make Makefile Hazel/Makefile Sandbox/Makefile

# Regenerate
./premake5 gmake2

# Build
make config=debug

# Run
./bin/Debug-macosx-ARM64/Sandbox/Sandbox
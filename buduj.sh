mkdir -p build
cd build
cmake .. || exit 1
make -j$(nproc) || exit 1

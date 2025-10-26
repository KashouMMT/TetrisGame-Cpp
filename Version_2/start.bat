@echo off
echo === Cleaning old build ===
if exist build (
    rmdir /s /q build
)
echo === Configuring project ===
cmake -S . -B build -G "MinGW Makefiles"
echo === Building project ===
cmake --build build -j
echo === Done ===

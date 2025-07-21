# Morpion

A simple project to learn about **CMake**, **CPack**, and get familiar with **GitHub**.

## How to compile (in MINGW environnement):

make a build directory, then make the following commands :

```bash
cmake ../src/ -G "MinGW Makefiles"  
cmake --build .
```

# How to Package

In the build directory, you need to make a directory named "deploy".
This directory needs to contain the depedencies dll of the project.
You can find these DLLs in the .zip file available in the release section.

After that, you can make the command "Cpack" (after a build).


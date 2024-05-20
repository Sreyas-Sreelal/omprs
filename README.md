# omprs

Component for open.mp to load gamemodes written in Rust.

## Tools

* [CMake 3.19+](https://cmake.org/)
* [Conan 1.57+](https://conan.io/) (You can't use conan v2.x, so may need to [download directly from github releases](https://github.com/conan-io/conan/releases) or install it using `pip3 install conan==1.57.0`)

## Tools on Windows

* [Visual Studio 2019+](https://www.visualstudio.com/)

Visual Studio needs the `Desktop development with C++` workload with the `C++ Clang tools for Windows` component.

## Building on Windows

```bash
git clone --recursive https://github.com/Sreyas-Sreelal/omprs
cd omprs
mkdir build
cd build
cmake .. -A Win32 -T ClangCL
cmake --build . --config RelWithDebInfo
```

## Building on Linux

```bash
apt update && apt install -y ninja-build clang-11 python3-pip libstdc++6 libc6
pip install --upgrade pip setuptools wheel
pip3 install --user -v "conan==1.59.0"
pip3 install --user -v "cmake==3.23.3"
git clone --recursive https://github.com/Sreyas-Sreelal/omprs
cd omprs
cmake -S . -B build -G Ninja
cmake --build build
```

## Installation 

Copy `Rust.dll` or `Rust.so` (64 or 32 bit depending on your open.mp server) to `components` folder
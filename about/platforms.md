---
title: Platforms
---

This document lists the platform requirements for working with the
S2 Geometry Library.

## Requirements for End Users

* [CMake](http://www.cmake.org/)
* A C++ compiler with C++11 support, such as [g++](https://gcc.gnu.org/)
  \>= 4.7.
* [gflags command line flags](https://github.com/gflags/gflags)
* [glog logging module](https://github.com/google/glog)
* [OpenSSL](https://github.com/openssl/openssl) (for its bignums)
* [googletest testing framework](https://github.com/google/googletest)
  (to build tests, optional)
* A POSIX system (for getrusage).

On Ubuntu, all of these can be installed via apt-get:

```
sudo apt-get install cmake libgflags-dev libgoogle-glog-dev libgtest-dev openssl
```

Otherwise, you may need to install some from source.

On macOS, use [MacPorts](http://www.macports.org/) or
[Homebrew](http://brew.sh/).  For MacPorts:
`sudo port install cmake gflags google-glog openssl`. Do not
install `gtest` from MacPorts; instead download
[release 1.8.0](https://github.com/google/googletest/releases/tag/release-1.8.0), unpack,
and run `cmake` with
`-DGTEST_ROOT=.../googletest-release-1.8.0/googletest`.

Thorough testing has only been done on Ubuntu 14.04.3 and macOS 10.12.

## Build and Install

```
mkdir s2-geometry-library
cd s2-geometry-library
tar zxvf $PATH_TO_DOWNLOADED_TGZ
mkdir build
cd build
cmake -DGTEST_ROOT=/usr/src/gtest ..  # Omit -DGTEST_ROOT to skip tests.
make
make test  # If GTEST_ROOT specified above.
sudo make install
```
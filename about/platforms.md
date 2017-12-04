---
title: Platforms
---

This document lists the platform requirements for working with the
S2 Geometry Library.

## Requirements for End Users

* A POSIX system (for `getrusage()`).
* [CMake](http://www.cmake.org/){:target="_blank"}
* A C++ compiler with C++11 support, such as
  [g++](https://gcc.gnu.org/){:target="_blank"} >= 4.7.
* [gflags command line flags](https://github.com/gflags/gflags){:target="_blank"}
* [glog logging module](https://github.com/google/glog){:target="_blank"}
* [OpenSSL](https://github.com/openssl/openssl){:target="_blank"} (for its bignum library)
* [googletest testing framework](https://github.com/google/googletest){:target="_blank"}

Note: on MacOSX, XCode requires command-line tools, which can be installed
with:

```
xcode-select --install
```
`
On Ubuntu, all of these packages can be installed via apt-get:

```
sudo apt-get install cmake libgflags-dev libgoogle-glog-dev libgtest-dev openssl
```

Otherwise, you may need to install some from source.

On macOS, use [MacPorts](http://www.macports.org/){:target="_blank"}:

`sudo port install cmake gflags google-glog openssl`.

Do not install `gtest` from MacPorts; instead download
[release 1.8.0](https://github.com/google/googletest/releases/tag/release-1.8.0){:target="_blank"}
, unpack, and substitute `cmake`
`-DGTEST_ROOT=/<i>path_to_googletest</i>/googletest-release-1.8.0/googletest`
in the build instructions below.

Thorough testing has only been done on Ubuntu 14.04.3 and macOS 10.12.

## Build and Install

Download [ZIP file](https://github.com/google/s2geometry/archive/master.zip)

```
cd [parent of directory where you want to put S2]
unzip [path to ZIP file]/s2geometry-master.zip
cd s2geometry-master
mkdir build
cd build
\# You can omit -DGTEST_ROOT to skip tests; 
\# Note: DGTEST_ROOT must be set to an absolute path. See above for macOS.
\# which should point to your googletest installation directory.
cmake -DGTEST_ROOT=/usr/src/gtest ..
make
make test  # If GTEST_ROOT specified above.
sudo make install
```
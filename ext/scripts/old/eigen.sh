#!/bin/bash
set -ex
ROOT_DIR=$(cd `dirname $0`/..;pwd)
# wget https://github.com/eigenteam/eigen-git-mirror/archive/3.3.4.tar.gz

PREFIX="/usr/local"

if [ $# -eq 1 ]; then
    PREFIX=$1
elif [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi
tar -xzvf "$ROOT_DIR"/sources/eigen-git-mirror-3.3.4.tar.gz
cd eigen-git-mirror-3.3.4/ && \
    mkdir -p build_dir && cd build_dir && \
    cmake -DCMAKE_INSTALL_PREFIX=$PREFIX ../ && \
    make && \
    make install && cd ../../
rm -rf eigen-git-mirror-3.3.4

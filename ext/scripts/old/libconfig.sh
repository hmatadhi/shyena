#!/bin/bash
set -ex
ROOT_DIR=$(cd `dirname $0`/..;pwd)
# wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz

PREFIX="/usr/local"

if [ $# -eq 1 ]; then
    PREFIX=$1
elif [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi
tar -xzvf "$ROOT_DIR"/sources/libconfig-1.7.2.tar.gz

cd libconfig-1.7.2 && \
    autoreconf -f -i && \
    ./configure --prefix=$PREFIX && \
    make && make install && cd -

rm -rf libconfig-1.7.2

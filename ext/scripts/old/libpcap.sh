#!/bin/bash
set -ex
ROOT_DIR=$(cd `dirname $0`/..;pwd)

PREFIX="/usr/local"

if [ $# -eq 1 ]; then
    PREFIX=$1
elif [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi
tar -xzvf "$ROOT_DIR"/sources/libpcap-1.8.1.tar.gz

cd libpcap-1.8.1 && \
    autoreconf -f -i && \
    ./configure --prefix=$PREFIX && \
    make && make install && cd -

rm -rf libpcap-1.8.1

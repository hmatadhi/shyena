#!/bin/bash
set -ex
ROOT_DIR=$(cd `dirname $0`/..;pwd)
# wget https://sourceforge.net/projects/geographiclib/files/distrib/GeographicLib-1.49.tar.gz

INSTALL_DIR="/usr/local"

if [ $# -eq 1 ]; then
    INSTALL_DIR=$1
elif [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

tar -xzvf "$ROOT_DIR"/sources/GeographicLib-1.49.tar.gz
cd GeographicLib-1.49 && \
    make PREFIX=$INSTALL_DIR -j6 && \
    make PREFIX=$INSTALL_DIR install
sudo rm -rf GeographicLib-1.49

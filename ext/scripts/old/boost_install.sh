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
# Install boost from sources

BOOST_MAJOR_VER="1"
BOOST_MINOR_VER="66"
BOOST_MINOR_REV="0"

BOOST_VER="$BOOST_MAJOR_VER.$BOOST_MINOR_VER.$BOOST_MINOR_REV"

BOOST_DIR="/tmp/boost"
BOOST_SOURCE_TAR_BZ=""$BOOST_DIR"/boost.tar.bz2"
BOOST_SOURCE_TAR=""$BOOST_DIR"/boost.tar"
BOOST_SOURCE_DIR=""$BOOST_DIR"/boost"

rm -rf "$BOOST_DIR"
mkdir -p "$BOOST_DIR"

if [ ! -e "$BOOST_SOURCE_TAR_BZ" ]; then
    cp "$ROOT_DIR"/sources/boost_"$BOOST_MAJOR_VER"_"$BOOST_MINOR_VER"_"$BOOST_MINOR_REV".tar.bz2 "$BOOST_SOURCE_TAR_BZ"
fi

if [ ! -e "$BOOST_SOURCE_TAR" ]; then
	bzip2 --decompress --keep "$BOOST_SOURCE_TAR_BZ" --stdout > "$BOOST_SOURCE_TAR"
fi

mkdir -p "$BOOST_SOURCE_DIR";tar --verbose --extract --strip-components=1 --directory="$BOOST_SOURCE_DIR" --file="$BOOST_SOURCE_TAR"

export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:/usr/include/python2.7/"

cd "$BOOST_SOURCE_DIR" && \
	./bootstrap.sh --with-libraries=all --prefix=$PREFIX && \
	./b2 --build-type=complete --layout=tagged link=shared runtime-link=shared threading=multi && \
        ./b2 --build-type=complete --layout=tagged link=shared runtime-link=shared threading=multi install && \
    cd -

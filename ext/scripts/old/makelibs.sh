#!/bin/bash
set -ex

ROOT_DIR=$(cd `dirname $0`/..;pwd)
PREFIX="$ROOT_DIR/dist/"

mkdir -p $PREFIX
rm -rf $ROOT_DIR/dist/*

$ROOT_DIR/scripts/boost_install.sh $PREFIX
$ROOT_DIR/scripts/libconfig.sh $PREFIX
$ROOT_DIR/scripts/geographiclib.sh $PREFIX
$ROOT_DIR/scripts/libpcap.sh $PREFIX
$ROOT_DIR/scripts/eigen.sh $PREFIX


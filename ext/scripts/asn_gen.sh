#!/bin/bash
set -x

rootdir=`dirname $0`
rootdir="$rootdir/.."

dir_name="$rootdir"/asn/"$1"
namespace="$2"
files=`find "$dir_name" -maxdepth 1 -type f`

rm -rf "$rootdir"/src/"$1"/*.cpp
rm -rf "$rootdir"/inc/"$1"/*.h

for f in $files
do
    #echo "$file"
    filename="$(basename "$f")"
    echo $filename
    extension="${filename##*.}"
    filename="${filename%.*}"
    ASN1C="/opt/asn1c-v722/bin/asn1c"
    $ASN1C "$f" -c++ -html -o "$rootdir/$1/src" -print -trace -genBitMacros -per -oh "$rootdir/"$1"/inc/" -static -stream -genTest -cppNs $namespace
done


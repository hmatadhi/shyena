#!/bin/sh
set -x
cd ext
mv archives/* . 
echo "Step1: Create ASN1 Directory"
tar -xzvf asn.tar.gz
echo "Step2: Create PCAP Autogen ASN Parser"
tar -xzvf pcap.tar.gz
echo "Step3: Create Boost Directory"
tar -xzvf boost_1_72_0.tar.gz
echo "Step4: Create DSI Directory"
cd ..
cd lib
ln -s ../ext/asn ./asn
ln -s ../ext/pcap ./pcap
ln -s ../ext/boost_1_72_0 boost_1_72_0
cd ..


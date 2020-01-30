wget https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.tar.gz
tar -xzvf boost_1_72_0.tar.gz
mv  boost_1_72_0.tar.gz archives
sudo ./bootstrap.sh --with-libraries=all --prefix=/usr/local
sudo ./b2 --build-type=complete --layout=tagged link=shared runtime-link=shared threading=multi
sudo ./b2 --build-type=complete --layout=tagged link=shared runtime-link=shared threading=multi install

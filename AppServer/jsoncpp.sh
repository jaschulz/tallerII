#!/bin/bash

root_dir=`pwd`
install_dir="$root_dir/temp_install"

# Remove old libraries, ensure use right versions
echo "Search and remove old libs"
    find / -type f -name "libjsoncpp.a" -exec rm {} \;
echo "Search end"

cd $install_dir
echo "Installing jsoncpp"
wget https://github.com/open-source-parsers/jsoncpp/archive/0.y.z.zip && \
unzip 0.y.z.zip && \
cd jsoncpp-0.y.z && \
python amalgamate.py && \
cd dist && \
gcc -c jsoncpp.cpp && \
ar rvs libjsoncpp.a jsoncpp.o && \
sudo cp libjsoncpp.a /usr/lib && \


cd $root_dir
rm -rf temp_install

echo "Make and install"
mkdir -p build && cd build && \
cmake .. && make

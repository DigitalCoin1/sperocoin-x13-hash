#!/bin/bash
set -ev

BUILD_REPO_URL=https://github.com/DigitalCoin1/sperocoin-x13-hash

cd build

git clone --branch $TRAVIS_TAG $BUILD_REPO_URL sperocoin-x13-hash

docker run --rm \
    -v $(pwd):/root/sperocoin-x13-hash \
    -t zebralucky/zbarw-build \
    /root/sperocoin-x13-hash/sperocoin-x13-hash/contrib/travis/build.sh

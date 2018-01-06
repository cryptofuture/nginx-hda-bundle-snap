#!/bin/bash

TESTARCH=$(uname -m)
cp -a ../../../modules/. ../../../stage/modules/

if [ "$TESTARCH" == "x86_64" ]
then
# https://dl.google.com/dl/page-speed/psol/1.13.35.1-x64.tar.gz
    tar xfz ../../../binary/1.13.35.1-x64.tar.gz -C ../../../stage/modules/ngx_pagespeed/
elif [ "$TESTARCH" == "amd64" ]
then
    tar xfz ../../../binary/1.13.35.1-x64.tar.gz -C ../../../stage/modules/ngx_pagespeed/
elif [ "$TESTARCH" == "i686" ]
# https://dl.google.com/dl/page-speed/psol/1.13.35.1-ia32.tar.gz
then
    tar xfz ../../../binary/1.13.35.1-ia32.tar.gz -C ../../../stage/modules/ngx_pagespeed/
elif [ "$TESTARCH" == "i386" ]
then
    tar xfz ../../../binary/1.13.35.1-ia32.tar.gz -C ../../../stage/modules/ngx_pagespeed/
else
    echo "$TESTARCH"
fi

# Builds with brotli 8d3fdc1dfe9a89079c18fd6428f19cac3edf53de
    tar xfz ../../../binary/brotli.tar.gz -C ../../../stage/modules/ngx_brotli/deps/brotli/ --strip-components=1

#!/bin/bash

set -e

cp -rf $SNAP/etc/nhb-snap /etc/nhb-snap/ "$@"
echo 'INFO: nginx configuration folder created!'

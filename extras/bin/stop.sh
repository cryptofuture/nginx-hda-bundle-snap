#!/bin/bash

set -e

$SNAP/bin/nginx -s stop -c /etc/nhb-snap/nginx.conf "$@"
echo 'INFO: nginx stopped'

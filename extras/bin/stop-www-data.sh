#!/bin/bash

set -e

$SNAP/bin/nginx -s stop -c /etc/nhb-snap/nginx-www-data.conf "$@"
echo 'INFO: nginx stopped'

#!/bin/bash

set -e

$SNAP/bin/nginx -s reload -c /etc/nhb-snap/nginx-www-data.conf "$@"
echo 'INFO: nginx reloaded'

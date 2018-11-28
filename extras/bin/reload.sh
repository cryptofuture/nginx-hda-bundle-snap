#!/bin/bash

set -e

$SNAP/bin/nginx -s reload -c /etc/nhb-snap/nginx.conf "$@"
echo 'INFO: nginx reloaded'

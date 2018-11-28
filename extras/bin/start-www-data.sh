#!/bin/bash

set -e

$SNAP/bin/nginx -c /etc/nhb-snap/nginx-www-data.conf "$@"
echo 'INFO: nginx started'

#!/bin/bash

set -e

$SNAP/bin/nginx -c /etc/nhb-snap/nginx.conf "$@"
echo 'INFO: nginx started'

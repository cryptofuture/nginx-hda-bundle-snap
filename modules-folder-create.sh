#!/bin/bash

set -e

cp -rf ./nginx-hda-bundle/debian/extra ./modules "$@"
echo 'INFO: Modules Folder created!'

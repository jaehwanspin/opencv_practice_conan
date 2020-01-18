#!/bin/bash

sudo -A apt-get update
sudo -A apt-get install -y --no-install-recommends pkg-config
sudo -A apt-get install -y --no-install-recommends autoconf
sudo -A apt-get install -y --no-install-recommends libpulse-dev:amd64
sudo -A apt-get install -y --no-install-recommends libgtk-3-dev:amd64

pip3 install opencv-python
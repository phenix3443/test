#!/bin/bash
cur_dir=$(cd $(dirname $0); pwd)
project_dir=$(realpath $cur_dir/..)
export GOPATH=${project_dir}
export PATH=$PATH:$GOPATH/bin

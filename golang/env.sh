#!/bin/bash
# -*-coding:utf-8 -*-
SCRIPT_DIR=$(cd $(dirname "$0"); pwd)
export GOPATH=$(go env GOPATH):${SCRIPT_DIR} # 将当前目录添加到gopath
echo ${GOPATH}

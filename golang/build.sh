#!/bin/bash
# export GOPATH=$(go env GOPATH):$(pwd)
# -*-coding:utf-8 -*-
SCRIPT_DIR=$(cd $(dirname "$0"); pwd)
WORKSPACE=${SCRIPT_DIR}

export GOPATH=$(go env GOPATH):${WORKSPACE} # 将当前目录添加到gopath
echo gopath: ${GOPATH}
export PATH=${PATH}:${WORKSPACE}/bin
echo path ${PATH}

go build lang/hello_go

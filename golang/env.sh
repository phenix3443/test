#!/bin/bash
# -*-coding:utf-8 -*-
SCRIPT_DIR=$(cd $(dirname "$0"); pwd)
PROJECT_DIR=$(realpath ${SCRIPT_DIR})
export GOPATH=${GOPATH}:${PROJECT_DIR} # 将当前目录添加到
echo ${GOPATH}

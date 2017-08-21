#!/bin/bash
# 项目构建脚本
project_name=hello

if [ ! -d "src/${project_name}" ]; then
	echo "项目代码必须放在src/${project_name}下"
	exit 1
fi

script_dir=$(cd $(dirname "$0"); pwd)
project_dir=$(realpath ${script_dir})
export GOPATH=${GOPATH}:${project_dir} # 将当前目录添加到
# echo ${GOPATH}

go get -v -x ${project_name}/...
go install ${project_name}

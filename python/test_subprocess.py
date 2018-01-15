#!python3
# -*- coding:utf-8 -*-

import subprocess

if __name__ == "__main__":
    res = subprocess.run("ls -l ", shell=True, check=True)

#!/bin/bash
# 测试字符串的相关
str="hello,world"
echo 字符串长度：${#str}
echo 从指定位置开始提取子串：${str:0}
echo 从指定位置开始，提取指定长度的子串：${str:0:2}
echo 从开始，删除最短匹配的子串：${str#"*ll*"}
echo 从开始，删除最长匹配的子串：${str##ll}

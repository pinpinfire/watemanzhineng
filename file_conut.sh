#!/bin/bash

read  -p  "输入需要统计目录的绝对路径:"  fpath

file_num=$(ls -lR $fpath |grep "*_gt.json*"|wc -l)

echo  "文件的数量为:$file_num"


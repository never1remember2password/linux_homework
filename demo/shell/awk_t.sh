#!/bin/bash
#作者：何陈龙 时间：2020-12-14
#功能：实现提取/etc/passwd文件的每一行用户名，按格式输出
#这里我是拿输入的filename文件名替代/etc/passwd文件
read -p "输入你想提取的文件名：" filename
i=`cat $filename | wc -l`  #提取出该文件有多少行
for (( n=1;n<=i;n++))    #for循环来查看提取每一行
do
echo "The $n account is `sed -n "$n,1p" $filename | awk -F ":" '{print $1}'`" #这里的sed -n "$n,1p" 是单独提取出当前for循环中的第n行，后面是利用awk指定分隔符":"来提取第一列得到用户名
done


#!/bin/bash
#for循环实现累加1+2+3+4+5+...+n
#时间：2020-12-09 著：何陈龙 18446208
#先将变量赋初值，以防止报错
sum=0
i=0
read -p "Input target number n(int):" n #输入N
for ((i=0; i<=n; i=i+1)) #c语言的for风格循环
do
	sum=$(($i+$sum))
done
echo "1+2+3+..+$n计算结果为：$sum"


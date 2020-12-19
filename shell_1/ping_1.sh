#/bin/bash
#ping 百度
ping -c 1  www.baidu.com  &> demo/null #输出重定向练习
if  [ $? -eq 0 ]
then
	echo "success"
else 
	echo "failure"
fi

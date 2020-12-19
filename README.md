git init #初始化本地git仓库
git add README.md
git commit -m“首次提交”
git branch -M main  #根支
git remote add origin git@github.com:never1remember2password/linux_homework.git #远程连接
git push --set-upstream origin main
git remote rm origin

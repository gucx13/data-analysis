#!/bin/bash
for i in `ls /Users/guchenxi/Downloads/数据分析-课程`
do
echo $i 
done

num=1 
DIR=“testDir”
while (( $num < 5 )) 
do
if [ -d $DIR$num ]; 
then echo “$DIR$num exist!!“
else
mkdir $DIR$num 
fi
let num+=1 
done












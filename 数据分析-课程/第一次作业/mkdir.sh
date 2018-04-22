#!/bin/bash
num=1 
DIR="testDir"
while (( $num < 4 ))
do
      if [ -d $DIR$num.tex ]; 
      then 
      echo "$DIR$num exist!!"
else
touch $DIR$num.tex 
fi
let num+=1 
done

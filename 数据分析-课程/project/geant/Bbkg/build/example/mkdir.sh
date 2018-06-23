#!/bin/shell
i=1
while [ $i -le 1000 ]
do
mkdir example$i
i=$(($i+1))
done


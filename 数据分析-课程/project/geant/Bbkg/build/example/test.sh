#!/bin/shell
i=1
while [ $i -le 1000 ]
do
cd example$i
./../../exampleB3b ../../run1.mac 
 
i=$(($i+1))
cd ..
done

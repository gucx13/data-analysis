#coding = utf-8
import os
import time
path ='/Users/guchenxi/Downloads/workarea'

i=0
for file in os.listdir(path):
    if(os.path.isdir(path+'/'+file)):
        i+=1
        statinfo=os.stat( "/Users/guchenxi/Downloads/workarea/"+file)
        if(statinfo.st_mtime>1521114000.00):
            print(file)

print i

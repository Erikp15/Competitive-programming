import sys
import random

n = random.randint(100000,100000)

file = open('testcase.txt','w')

file.write(f'{n}\n')
for i in range(0,n):
    file.write(f'{random.randint(-n*10,n*10)} {random.randint(-n*10,n*10)}\n')
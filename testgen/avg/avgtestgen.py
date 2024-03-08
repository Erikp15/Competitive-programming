import random

file = open('in','w')

MAX_N = 2000000000
a = random.randrange(MAX_N)
b = random.randrange(MAX_N)
file.write(f'{a} {b}\n')
    

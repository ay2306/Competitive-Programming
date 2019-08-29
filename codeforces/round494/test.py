import random
fopen = open('input.txt','w+')
a = random.randint(1,101)
b = random.randint(1,101)
x = random.randint(1,a+b)
fopen.write(str(a)+' ' + str(b) + ' ' + str(x))
fopen.close()

import random
fopen = open('input.txt','w+')
t = random.randint(1,100)
fopen.write(str(t) + "\n")
for i in range(t):
    n = random.randint(1,10)
    fopen.write(str(n)+"\n")
    for ada in range(n):
        fopen.write(str(random.randint(1,9)) + " ")
    fopen.write('\n')
fopen.close()

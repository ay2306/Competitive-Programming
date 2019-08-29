fopen = open('input.txt','w+')
i = 1000
fopen.write(str(i)+'\n')
for k in range(i):
    s = ''
    for j in range(i):
        s = s+'1000000000 '
    fopen.write(s + '\n')
fopen.close()
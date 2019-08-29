# import sys
# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')

while(True):
    a = input()
    if a == 'DONE':
        break
    a = ''.join(a.split(' '))
    a = ''.join(a.split('.'))
    a = ''.join(a.split(','))
    a = ''.join(a.split('!'))
    a = ''.join(a.split('?'))
    a = a.lower()
    i = 0
    j = len(a)-1
    flag = 1
    while i < j:
        if a[i] != a[j]:
            flag = 0
            break
        i = i + 1
        j = j - 1
    if flag == 1:
        print('You won\'t be eaten!')
    else:
        print('Uh oh..')
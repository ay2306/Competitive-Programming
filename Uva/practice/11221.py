from math import *
import sys
# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')
cas = 1
t = int(input())
for limca in range(t):
    a = input()
    print('Case #' + str(cas) + ':')
    cas = cas+1
    a = ''.join(a.split(' '))
    a = ''.join(a.split('.'))
    a = ''.join(a.split(','))
    a = ''.join(a.split('!'))
    a = ''.join(a.split('?'))
    a = ''.join(a.split(')'))
    a = ''.join(a.split('('))
    l = len(a)
    sq = int(sqrt(l))
    # print(sq*sq)
    # print(l)
    if (sq*sq != l):
        print('No magic :(')
    else:   
        j =int(sqrt(l))
        arr = []
        tarr = []
        for i in range(l):
            if i%j == 0 and len(tarr) != 0:
                arr.append(tarr)
                tarr = []
                tarr.append(a[i])
            else:
                tarr.append(a[i])
        if(len(tarr) != 0):
            arr.append(tarr)
        # for i in arr:
        #     print (i)
        magic = True
        e = len(arr)
        # f = len(arr[0])
        i = 0
        j = 0
        while(i < e):
            j = 0
            while(j < e):
                # print('i = ' + str(i) + '  j = ' + str(j))
                if(arr[i][j] == arr[e-i-1][e-j-1] and arr[j][i] == arr[e-j-1][e-i-1] and arr[i][j] == arr[j][i]):
                    j = j+1
                else:
                    magic = False
                    break
            i = i + 1
            if(not magic):
                break
        if magic:
            print(e)
        else:
            print('No magic :(')

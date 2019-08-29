# import sys
# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')
t = int(input())
for pikachu in range(t):
    a = input()
    arr = []
    for i in list(a):
        if i == ':':
            continue
        else:
            arr.append(i)
    # print(arr)
    # arr[0] = arr[1].split('')
    n = 1*int(arr[3]) + 10*int(arr[2]) + 100*int(arr[1]) + 1000*int(arr[0])
    n = n+1
    while(1):
        if((n%100) >= 60):
            n = n+100
            n = n-(n%100)
        if n == 2400:
            n = 0
        p = str(n)
        if(p == p[::-1]):
            break
        else:
            n = n+1
    arr[3] = str(n%10)
    arr[2] = str(int((n%100)/10))
    arr[1] = str(int((n%1000)/100))
    arr[0] = str(int((n%10000)/1000))
    print(arr[0] + arr[1] + ':' + arr[2] + arr[3])
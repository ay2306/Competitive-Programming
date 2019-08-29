# from sys import stdin,stdout
t = int(input())
for kk in range(t):
    m = int(input())
    num = m+1
    denom = 1
    ans = []
    while num <= 2*m:
        if (num*m)%denom == 0:
            ans.append(num)
        num = num+1
        denom = denom+1
    print(len(ans))
    for i in ans:
        print(i)
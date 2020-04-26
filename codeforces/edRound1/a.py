import math
t = int(input())
for i in range(t):
    n = int(input())
    ans = (n*(n+1))//2
    k = 1
    while k <= n:
        ans-=(k+k)
        k*=2
    print(ans)
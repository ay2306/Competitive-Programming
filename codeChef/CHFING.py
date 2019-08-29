import math
def solve():
    mod = 1000000007
    inp = [int(e) for e in input().split()]
    n = inp[0]
    k = inp[1]
    ld = int((k-1)/(n-1))
    if((k-1)%(n-1) == 0):
        ld = ld-1
    ans = ld*k
    ans = int(ans)%mod
    pt = (ld*(ld+1))/2
    pt = int(pt)%mod
    pt = pt*n
    pt = int(pt)%mod
    ans = ans - pt
    if ans < 0:
        ans = ans + mod
    pt = (ld * (ld-1))/2
    pt = int(pt)%mod
    ans = ans + pt
    ans = int(ans)%mod
    ans = ans + k-1
    ans = ans%mod
    print(int(ans))
t = int(input())
for i in range(t):
    solve()
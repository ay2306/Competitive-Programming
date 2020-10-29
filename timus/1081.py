num = []
dp = []

def solve(pos, f, prv):
    global num
    global dp
    if pos == len(num):
        return 1
    res = dp[pos][f][prv]
    if res != -1:
        return res
    res = 0
    limit = 1
    if prv:
        limit = 0
    if not f:
        limit = min(limit,num[pos])
    for i in range(0,limit+1):
        res += solve(pos + 1, f or (i != limit), i == 1)
    dp[pos][f][prv] = res
    return res

def cnt(k):
    global num
    global dp
    num = []
    dp = [[[-1,-1],[-1,-1]] for e in range(200)]
    while k > 0:
        num.append(k%2)
        k = k // 2
    num = num[::-1]
    return solve(0,False,False)

n,k = map(int,input().split())
ans = 2**100
lo = 0
hi = ans
while lo <= hi:
    mid = (lo + hi) // 2
    cal = cnt(mid)
    if(cal < k):
        lo = mid + 1
    else:
        hi = mid - 1
        ans = mid
res = ""
while(ans > 0):
    if ans % 2 == 1:
        res += "1"
    else:
        res += "0"
    ans = ans // 2
while len(res) < n:
    res += "0"
res = res[::-1]
if(len(res) != n):
    print(-1)
else:
    print(res)
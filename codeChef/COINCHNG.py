from sys import stdin,stdout
def solve():
    g = stdin.readline()
    c,s,k = map(int,g.split())
    dp = [[0 for i in range(600)] for j in range(65)]
    if s == 0:
        print(0)
        return
    if c == 1:
        print(1)
        return
    n = 0
    for i in range(s+1):
        dp[0][i] = 0
        if i == 0:
            dp[0][i] = 1
    n = 0
    power = 1
    while dp[n][s] < k:
        if n > 0:
            power*=c
        n+=1
        dp[n][0] = 1
        for i in range(s+1):
            if i == 0:
                continue
            for j in range(c):
                if(i-j < 0):
                    break
                dp[n][i] += dp[n-1][i-j]
    ans = 0
    while n > 0:
        dig = 0
        while dp[n-1][s-dig] < k:
            k-=dp[n-1][s-dig]
            dig+=1
        ans += (power*dig)
        power = power//c
        n-=1
        s-=dig
    stdout.write(str(ans)+'\n')
t = int(stdin.readline())
for i in range(t):
    solve()
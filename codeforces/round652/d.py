mod = 10**9 + 7
N = 2*(10**4) + 100
dp = [[0,0] for i in range(N)]
i = 3
while i < N:
    print(i)
    dp[i][1] = 2*dp[i-2][0] + dp[i-1][0]
    dp[i][0] = max(dp[i][0],dp[i-1][0]+dp[i-2][0]+dp[i-2][0])
    dp[i][0] = max(dp[i][0],dp[i-1][0]+dp[i-2][0]+dp[i-2][1])
    dp[i][0] = max(dp[i][0],dp[i-1][0]+dp[i-2][1]+dp[i-2][0])
    dp[i][0] = max(dp[i][0],dp[i-1][0]+dp[i-2][1]+dp[i-2][1])
    dp[i][0] = max(dp[i][0],dp[i-1][1]+dp[i-2][0]+dp[i-2][0])
    dp[i][0] = max(dp[i][0],dp[i-1][1]+dp[i-2][0]+dp[i-2][1])
    dp[i][0] = max(dp[i][0],dp[i-1][1]+dp[i-2][1]+dp[i-2][0])
    dp[i][0] = max(dp[i][0],dp[i-1][1]+dp[i-2][1]+dp[i-2][1])
    i+=1
t = int(input())
for i in range(t):
    n = int(input())
    print(max(dp[n][0],dp[n][1])%mod)
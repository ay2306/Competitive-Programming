dp = []
for i in range(100100):
    dp.append([0,0])
dp[1][1] = 1
dp[1][0] = 1

for i in range(2,100100):
    dp[i][1] = dp[i-1][0] + dp[i-1][1]
    dp[i][0] = dp[i-1][1]

# print(dp)
n = int(input())
print(dp[n][1] + dp[n][0])

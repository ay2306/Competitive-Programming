"""
 * This is classical dp question
 ! No need to solve mathematics
 * dp[positions][state][current_sum]
 * positions can never be over 50 (as mentioned )
 ? state are only 2 possible: either equal or smaller but there is no number to compare so find out possible sum to be S?
 * * This saves the second state position, N and sum needs to be S
 * Thus dp[postions][sum]

"""
# ! Global Variables
dp = []
n = 0
s = 0
num = []
def calculate(pos = 0, sum = 0):
    if(pos == n):
        if(sum == s):
            return 1
        else:
            return 0
    if(sum > s):
        return 0
    if dp[pos][sum] != -1:
        return dp[pos][sum]
    dp[pos][sum] = 0
    for i in range(10):
        num[pos] = i
        dp[pos][sum] += calculate(pos+1,sum+i)
    return dp[pos][sum]

n,s = map(lambda x: int(x),input().split())
for i in range(n+10):
    arr = []
    for j in range(s+10):
        arr.append(-1)
    dp.append(arr)
num = [-1]*n
if s % 2 == 1:
    print(0)
else:
    s = s//2
    print(calculate()*calculate())
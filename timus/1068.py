n = int(input())
ans = 0
if n > 0:
    ans = (n*(n+1))//2
elif n == 0:
    ans = 1
else :
    n *= -1
    ans = (n*(n+1))//2
    ans -= 1
    ans *= -1
print(ans)

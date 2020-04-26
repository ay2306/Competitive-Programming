n = int(input())
hi = (10**n)-1
lo = (10**(n-1))-1
ans = hi-lo + hi//2 - lo + hi//5 - lo
if(n > 1):
    ans += hi//4 - lo
if(n > 2):
    ans += hi//8 - lo
print(ans)
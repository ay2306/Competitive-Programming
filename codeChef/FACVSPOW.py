import math

def lnfact(n):
    ans =  n*math.log(n)
    ans = ans - n
    ans = ans + (0.5 * math.log(math.pi*2*n))
    return ans

def check(n,a):
    k = lnfact(n)
    k = k/math.log(a)
    if k > n:
        return True
    return False



t = int(input())

for ka in range(t):
    a = int(input())
    low = 1
    high = 1000000
    ans = high
    while low <= high:
        mid = int((low+high)/2)
        if check(mid,a):
            ans = min(mid,ans)
            high = mid-1
        else:
            low = mid+1
    print(ans)
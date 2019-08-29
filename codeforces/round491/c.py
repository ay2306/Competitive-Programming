def check(n,k):
    t = 0
    r = 0
    while n > 0:
        t = t + 1
        if n <= k:
            n = 0
        else:
            r = r + int((n-k)/10)
            n = 9*(n-k)
            n = int(n/10)
    if(t*k >= r):
        return True
    else:
        return False    
n = input()

low = 1
high = n
ans = -2
while low <= high:
    mid = int((low+high)/2)
    if check(n,mid):
        ans = mid
        high = mid - 1
    else:
        low = mid + 1
print ans
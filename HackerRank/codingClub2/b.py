def check(x,arr):
    f = 1
    for i in arr:
        f = f*(i/x)
    if f>=1:
        return False
    return True


n = int(input())
inp = input()
arr = [int(e) for e in inp.split()]
ans = 10000000000
l = 1
r = ans
while l<=r:
    mid = (l+r)/2
    mid = int(mid)
    if(check(mid,arr)):
        r = mid-1
        ans = mid
    else:
        l = mid+1
print(ans)
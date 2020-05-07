eps = 10**(-8)
def solve():
    n = int(input())
    arr = []
    neg = 0
    for i in range(n):
        x,y = map(int,input().split())
        arr.append((x,y))
        if y < 0:
            neg += 1
    if neg != 0 and neg != n:
        print(-1)
        return 0
    ans = 10**16
    lo = 0
    hi = ans
    while hi - lo > eps:
        mi = float(lo + hi) / 2.0
        left = -2*(10**20)
        right = -left
        for x,y in arr:
            dy = float(abs(abs(y)-mi))
            try :
                dx = float(pow(mi**2 - dy**2,1/2.0))
                left = max(left,x-dx)
                right = min(right,x+dx)
            except:
                left = 1
                right = 0
                break
        if right-left > eps:
            ans = mi
            hi = mi
        else:
            lo = mi
    print ("%.12f" % ans)
solve()

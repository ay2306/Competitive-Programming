import math
def bs(y,t):
    a = 1
    b = (2**(t+1) - 3)
    c = -2*y
    # print(a,b,c,((-b+math.sqrt(b*b-4*a*c)))/(a*2))
    return ((-b+math.sqrt(b*b-4*a*c)))/(a*2)

y = int(input())
ans = []
k = 0
if(y == 0):
    print(0,1)
else:
    while(k < 150):
        p = bs(y,k)
        if(math.ceil(p) == math.floor(p) and p > 0 and int(p)%2 == 1):
            ans.append(int(p*(2**k)))
        k+=1
    if len(ans) == 0:
        print(-1)
    else:
        ans = list(dict.fromkeys(ans))
        ans.sort()
        for i in ans:
            print(i,end=' ')
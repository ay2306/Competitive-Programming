eps = 1/100000.0;
a = 10**9
b = 10**18 + a
l = a
r = b
cnt = 0
while r > eps+l:
    mid = (l+r)/2.0
    cnt += 1
    if r-mid > mid - l:
        l = mid
    else:
        r = mid
print("Steps using Arithmetic Mean:",cnt)
l = a
r = b
cnt = 0
while r > eps+l:
    gm = (l*r)**(1/2.)
    cnt += 1
    # print(r-l)
    if r-gm >= gm-l:
        l = gm
    else :
        r = gm
print("Steps using Geometric Median:",cnt)

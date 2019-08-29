import math
t = int(input())
for ll in range(t):
    n = int(input())
    reb = [int(e) for e in input().split()]
    r = [int(e) for e in input().split()]
    lcm = reb[0]
    for i in reb[1:]:
        lcm = (lcm*i)/math.gcd(lcm,i)
    a = int((r[0]-1)/lcm)
    b = int(r[1]/lcm)
    a = b-a
    b = r[1]-r[0]+1
    print(b-a)
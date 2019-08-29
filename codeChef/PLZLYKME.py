import math
def solve():
    inp = [int(e) for e in input().split()]
    l = inp[0]
    d = inp[1]
    s = inp[2]
    c = inp[3]
    #   main logic is this:
    #   L = s*((1+c)^(k-1))
    #   log L = log s + (k-1)log(1+c)
    #   (logL - log(s))/log(1+c) + 1 = k
    k = (math.log(l) - math.log(s))/math.log(1+c) + 1
    if d-k >= 0.0000000:
        print ("ALIVE AND KICKING")
    else:
        print ("DEAD AND ROTTING")
t = int(input())
for i in range(t):
    solve()

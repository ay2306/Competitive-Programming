def solve():
    x = int(input())
    for i in range(1,10**5):
        sq = int(pow(x+i**2,0.5))
        if sq*sq == (x+i**2)**2:
            print(sq,i*sq)
            return
    print(-1) 

t = int(input())
for i in range(t):
    solve()
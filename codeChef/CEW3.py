def solve():
    inp = raw_input()
    n = int(inp.split(' ')[0])
    m = int(inp.split(' ')[1])
    if (n+m > 2):
        print "1.000000"
    else:
        print "0.000000"
t = int(input())
for i in range(t):
    solve()
    

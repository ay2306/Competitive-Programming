def modPower(a,n,mod):
    if n == 0:
        return 1
    if n == 1:
        return a
    l = modPower(a,int(n/2))
    if n%2 == 0:
        return (l* l)
    l = l*l
    l = a*l
    return l

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def solve():
    inp = raw_input()
    arr = [int(e) for e in inp.split(' ')]
    a = arr[0]
    b = arr[1]
    n = arr[2]
    diff = a-b
    mod = diff
    if(diff == 0):
        mod = 1000000007
    g = modPower(a,n,mod)+modPower(b,n,mod)
    if(diff != 0):
        g = gcd(diff,g)
    ans = g%1000000007
    print (ans)
t = input()
t = int(t)  
for k in range(t):
    solve()
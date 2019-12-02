n = int(input())
k = int(input())
mod = int(input())
def multiply(a,b):
    e = []
    c = []
    e.append(((a[0][0]*b[0][0])%mod + (a[0][1]*b[1][0])%mod)%mod)
    e.append(((a[0][0]*b[0][1])%mod + (a[0][1]*b[1][1])%mod)%mod)
    c.append(e)
    e = []
    e.append(((a[1][0]*b[0][0])%mod + (a[1][1]*b[1][0])%mod)%mod)
    e.append(((a[1][0]*b[0][1])%mod + (a[1][1]*b[1][1])%mod)%mod)
    c.append(e)
    return c
def power(a,n):
    if n == 0:
        return [[1]*2]*2
    if n == 1:
        return a
    p = power(a,n//2)
    p = multiply(p,p)
    if n % 2:
        p = multiply(a,p)
    return p
u = [[k-1,k-1],[1,0]]
u = power(u,n-1)
ans = u[0][0]*(k-1) + u[0][1]
print(ans%mod)
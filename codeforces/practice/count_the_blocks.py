mod = 998244353
def f(n):
    if n == 1:
        print(10)
        return
    for i in range(1,n-1):
        print((((n-i-1)*810*pow(10,n-i-2,mod))%mod+(2*90*pow(10,n-i-1,mod))%mod)%mod,end=' ')
    print(180,10)
n = int(input())
f(n)

# //https://codeforces.com/problemset/problem/1332/E
mod = 998244353
n,m,l,r = map(int,input().split())
if n*m % 2 == 1:
    print(pow(r-l+1,n*m,mod))
else:
    print(((pow(r-l+1,n*m,mod)+(r-l+1)%2)*pow(2,mod-2,mod))%mod) 
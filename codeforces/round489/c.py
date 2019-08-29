mod = 1000000007
def modPower(a,b):
    global mod
    if(b == 1):
        return a%mod
    if(b == 0):
        return 1
    if(b%2 == 1):
        return ((a%mod)*modPower(a,b-1))%mod
    else:
        k = ((a%mod)*(a%mod))%mod
        return modPower(k,int(b/2))
inp = raw_input()
arr = []
for e in  inp.split(' '):
    arr.append(int(e))
n = arr[0]
k = arr[1]
if k == 0:
    print (2*n)%mod
elif n == 0:
    print (n)
else:
    a = modPower(2,k+1)
    a = ((a%mod)*(n%mod))%mod
    b = modPower(2,k)
    c = ((a%mod) - (b%mod))%mod
    print ((c+1)%mod)

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def coPrime(a,b):
    if gcd(a,b) == 1:
        return True
    return False


inp = raw_input()
arr = []
for e in  inp.split(' '):
    arr.append(int(e))
l = arr[0]
r = arr[1]
x = arr[2] 
y = arr[3]
p = y/x
c = 0

high = r
while l < r:
    print l
    if p%l == 0:
        if coPrime(l,p/l):
            if p/l <= r:
                c = c+1
                if l != p/l:
                    c = c+1
        high = p/l
    l = l + 1
print c
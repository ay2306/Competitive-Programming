
def gcd(a,b):
    if a == 0:
        # print("end at " + str(a) + " " +str(b))
        return b
    return gcd(b%a,a)
n = int(input())
n = n-1
inp = input()
arr = [int(inp.split(' ')[0]),int(inp.split(' ')[1])]
g = gcd(arr[0],arr[1])
print (g)
g = (arr[0]*arr[1])/g
for i in range(n):
    # print(g)
    inp = input()
    arr = []    
    arr.append(int(inp.split(' ')[0]))
    arr.append(int(inp.split(' ')[1]))
    gc = gcd(arr[0],g)
    dc = gcd(arr[1],g)
    fc = gcd(gc,dc)
    gc = gc/fc
    g = gc*fc
    d = arr[0]*arr[1]
    d = d/gc
    # print(str(d) + " " + str(g))
    # g = gcd(int(d),int(g))
    # print (gc)
if g == 1:
    print(-1)
else:
    print(int(g))


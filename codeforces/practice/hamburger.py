def maxi(a,b):
    if a > b:
        return a
    return b

s = raw_input()
inp = raw_input()
arr = []
for i in inp.split(' '):
    arr.append(int(i))
n = arr
arr = []
inp = raw_input()
for i in inp.split(' '):
    arr.append(int(i))
p = arr
r = raw_input()
r = int(r)
arr = [0,0,0]
# print list(s)
for i in list(s):
    if i == 'B':
        arr[0] = arr[0]+1
    if i == 'S':
        arr[1] = arr[1]+1
    if i == 'C':
        arr[2] = arr[2]+1
high = 1000000000000000
low = 0
cost = 0
ans = 0
while low <= high:
    cost = 0
    mid = low + (high-low)/2
    mid = int(mid)
    for i in range(3):
        cost = cost + maxi(0,(arr[i]*mid - n[i]))*p[i]
    if cost < r:
        ans = mid
        low = mid+1
    if cost > r:
        high = mid-1
    if cost == r:
        ans = mid
        break
print ans
# print s
# print n
# print p
# print r
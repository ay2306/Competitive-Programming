n = int(input())
arr = [int(e) for e in input().split()]
m={}
for i in arr:
    if i not in m:
        m[i] = 0
    m[i] += 1
ans = 0
f = {}
for i in range(n):
    tot = n
    left = i
    right = n-i-1
    if arr[i] not in f:
        f[arr[i]] = 0
    if (arr[i]+1) not in f:
        f[arr[i]+1] = 0
    if (arr[i]-1) not in f:
        f[arr[i]-1] = 0
    if arr[i] not in m:
        m[arr[i]] = 0
    if (arr[i]+1) not in m:
        m[arr[i]+1] = 0
    if (arr[i]-1) not in m:
        m[arr[i]-1] = 0
    left -= f.get(arr[i])
    left -= f.get(arr[i]-1)
    left -= f.get(arr[i]+1)
    f[arr[i]] += 1
    right -= (m.get(arr[i])-f.get(arr[i]))
    right -= (m.get(arr[i]+1)-f.get(arr[i]+1))
    right -= (m.get(arr[i]-1)-f.get(arr[i]-1))
    ans += (left*arr[i] - right*arr[i])
print(ans)
inp = [int(e) for e in input().split(' ')]
n = inp[0]
k = inp[1]
a = [int(e) for e in input().split(' ')]
ans = 0
a.sort(reverse=True)
for i in range(n):
    ans+=(((i//k)+1)*a[i])
print(ans)
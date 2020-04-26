p = [2,3,5,7,11,13,17,19,23,31,37,41,43,47,53,61,67,71]
t = int(input())
for i in range(t):
    n = int(input())
    cur = 1
    pos = True
    cnt = [1 for i in range(len(p)+1)]
    ans = 1
    while cur*2 <= n:
        mx = 0
        k = 0
        ind = 0
        hehe = 0
        for i in range(len(p)):
            if (ans//cnt[i])*(cnt[i]+1) > k and cur*p[i] <= n:
                hehe += 1
                k = (ans//cnt[i])*(cnt[i]+1)
                mx = cur*p[i]
                ind = i
        if hehe == 0:
            break
        ans = k
        cur = mx
        cnt[ind] += 1
    print(cur,ans)

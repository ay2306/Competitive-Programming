def solve():
    n = int(input())
    if n % 2 == 1:
        print(0)
        return
    cnt5 = 5
    ans = 0
    while cnt5*2 <= n:
        ans+=(n/cnt5)
        cnt5*=5
    print(ans)
solve()
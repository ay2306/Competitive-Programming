def factorial(n):
    ans = 1
    for i in range(1,n+1):
        ans = ans*i
    return ans
while True:
    inp = []
    try:
        a = input()
        inp = a.split(' ')
        if len(inp) == 1:
            continue
    except EOFError:
        break
    arr = [int(e) for e in input().split(' ')]
    ans = factorial(int(inp[0]))
    for i in arr:
        ans = ans//factorial(i)
    print(ans)
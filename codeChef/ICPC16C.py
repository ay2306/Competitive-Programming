t = int(input())
for cases in range(t):
    a = int(input())
    ans = ""
    while a > 0:
        if a > 9:
            ans = "9" + ans
            a = a-9
        else:
            ans = str(a) + ans
            a = 0
    a = int(ans)
    a = a+1
    k = 0
    while a > 0:
        k = k + a%10
        a = int(a/10)
    print(k)
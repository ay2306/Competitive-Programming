while True:
    steps = 0
    n = 1
    try:
        n = int(input())
    except EOFError:
        break
    st = 1
    while n > 1:
        st += 1
        if n % 2 == 0:
            n = n//2
        else:
            n = n + n + n + 1
    print(st)
q = input()
for query in range(q):
    res = 0
    mod = 1000000007
    inp = raw_input()
    n = (inp.split(' ')[0])
    t = (inp.split(' ')[1])
    k = 1
    i = 1
    while i <= t:
        k = k*(i+1)
        i = i + 1
    i = 1
    while i <= n:
        res = (res + k%mod)%mod
        i = i+1
        k = k/i
        k = k*(t+i)
    print (res)
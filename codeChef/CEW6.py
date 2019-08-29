def solve():
    a = input()
    A = 0
    B = 0
    i = 0
    while i < len(a):
        if a[i] == '1':
            A = A*10 + 1
        if a[i] == ' ':
            break
        i = i+1
    i = i+1
    while i < len(a):
        if a[i] == '1':
            B = B*10 + 1
        if a[i] == ' ':
            break
        i = i+1
    
    print (A*B)
t = int(input())
for i in range(t):
    solve()
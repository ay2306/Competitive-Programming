def pow(a,n):
    if n == 0:
        return 1
    if n == 1:
        return a
    p = pow(a,n//2)
    p = p*p
    if n % 2 == 1:
        p = p * a
    return p

for _ in range(int(input())):
    n, m = map(int, input().split(' '))
    print('%d.00'%(pow(2, n+1)-pow(2, m+1)))
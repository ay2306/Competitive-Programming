def factorial(n):
    if n < 0:
        return -1
    if n < 2:
        return 1
    if n not in cal:
        cal[n] = n*factorial(n-1)
    return cal[n]

cal = {}

t = int(input())
for i in range(t):
    n = int(input())
    print(factorial(n))
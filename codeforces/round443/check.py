def f1(x):
    x = x ^ 0
    x = x | 1
    x = x & 1021
    return x
n = int(input())
print(f1(n))

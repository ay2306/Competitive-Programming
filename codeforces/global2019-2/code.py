a = input()
a = a[::-1]
ans = 0
factor = 1
for i in a:
    k = ord(i) - ord('A') + 1
    ans = ans + (factor*k)
    factor = factor*26
print(ans)
import math
inp = int(input())
n = int(input())
right = 0
left = n
i = inp-1
ok = 1
ans = n
while i > 0:
    right = right+((left%10)*ok)
    ok = ok * 10
    rem = left % 10
    left = left//10
    if(rem != 0 and ans > left+right):
        ans = left+right
    i-=1
print(ans)
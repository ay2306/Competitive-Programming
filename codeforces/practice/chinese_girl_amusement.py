import math
import sys
sys.stdin = open('china.in','r')
sys.stdout = open('china.out','w')
n = int(input())
k = n//2
while math.gcd(k,n) != 1:
    k -= 1
print(k)
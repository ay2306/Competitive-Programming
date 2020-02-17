import math
import sys
sys.stdin = open("input.txt","r")
sys.stdout = open("output.txt","w")
t = int(input())
for abc in range(t):
    r,s = map(int,input().split())
    print(r,s)
    t1 = s//(2*math.pi*r)
    if(t1*2*math.pi*r < s):
        t1+=1
    print(t1)

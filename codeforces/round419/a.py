import sys
sys.stdout = open('in','w')
n,m = map(int,input().split())
print(n,m)
for i in range(n):
    for j in range(m):
        print(1,end=" ")
    print("")
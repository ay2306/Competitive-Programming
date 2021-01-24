t = int(input())
for i in range(t):
    l,r = map(int,input().split())
    mx = r*(r+1)//2 - l*(l-1)//2
    print(mx)
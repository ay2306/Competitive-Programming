k,n,w = map(int,input().split())
print(max((w*(w+1)//2)*k - n,0))
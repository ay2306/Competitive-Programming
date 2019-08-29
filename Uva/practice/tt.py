n=int(input())
a=1
thisString = ''
for k in range(n):
    thisString = ''
    for j in range(0,n-k-1):
        thisString = thisString + ' '
    for i in range(a):        
        thisString = thisString + '#'
    print(thisString)
    a=a+1
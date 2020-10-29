import random
def get(x,y):
    return random.randint(x,y)
def getList(st,en):
    arr = []
    while len(arr) < 8:
        x = get(st,en)
        if x not in arr:
            arr.append(x)
    return arr
n,m = map(int,input().split())
print(getList(n,m))

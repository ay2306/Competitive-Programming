fopen = open('input.txt','w')
import random
def getArray(array_length,element_lower_bound,element_upper_bound):
    arr = []
    for i in range(array_length):
        arr.append(random.randint(element_lower_bound,element_upper_bound))
    return arr
def writeArray(array, file = fopen):
    for i in array:
        file.write(str(i)+" " )
    file.write('\n')
def getNumber(element_lower_bound,element_upper_bound):
    return random.randint(element_lower_bound,element_upper_bound)
def writeNumber(number, file = fopen):
    file.write(str(number) + ' ')
    file.write('\n')
def getString(arr,length):
    S = ""
    i = 0
    while i < length:
        S = S + arr[random.randint(0,len(arr)-1)]
        i = i + 1
    return S
def writeString(S,file = fopen):
    file.write(str(S) + "\n")
capLetters = []
i = 65
while i <= 90:
    capLetters.append(chr(i))
    i = i + 1
smallLetters = []
i = 97
while i <= 122:
    smallLetters.append(chr(i))
    i = i + 1
digits = []
i = 0
while i < 10:
    digits.append(str(i))
    i = i + 1


n = getNumber(3,10)
edges = {}
times = {}
p = [-1 for i in range(n+10)]
# print(p)
for i in range(n+10):
    p[i] = i
def findParent(x):
    if p[x] != x:
        p[x] = findParent(p[x])
    return p[x]
def join(a,b):
    a = findParent(a)
    b = findParent(b)
    if a == b:
        return
    if p[a] < p[b]:
        i = a
        a = b
        b = a
    p[b] += p[a]
    p[a] = b
comp = n
while True:
    i = getNumber(1,n)
    j = getNumber(1,n)
    if i == j:
        continue
    if i > j:
        k = i
        i = j
        j = k
    a = (i,j)
    if a in edges:
        continue
    edges[a] = 1
    # print("adding i = ", i, "j = ", j)
    pi = findParent(i)
    pj = findParent(j)
    if pi != pj:
        join(i,j)
        # print(p)
        comp -= 1
    if comp == 1:
        break
m = len(edges)
arr = [n,m]
writeArray(arr)
for i in edges:
    writeArray(i)
  
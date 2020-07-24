fopen = open('input.txt','w')
import random
import sys
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

n_low = int(sys.argv[1])
n_high = int(sys.argv[2])
q_low = int(sys.argv[3])
q_high = int(sys.argv[4])

N = getNumber(n_low,n_high)

connected_components = N

parent = []
for i in range(N+1):
    parent.append(i)

def findParent(x):
    global parent
    if parent[x] == x:
        return x
    else:
        parent[x] = findParent(parent[x])
    return parent[x]

def join(a,b):
    a = findParent(a)
    b = findParent(b)
    if a == b:
        return False
    parent[a] = b
    return True

writeNumber(N)
arr = []
op = 0

if len(sys.argv) > 5:
    change = getNumber(1,N)
    for i in range(change):
        arr.append(10**8)
    for i in range(change,N):
        arr.append(N-i-1)
    writeArray(arr)
    for i in range(N-1):
        arr = [i+1,i+2]
        writeArray(arr)
    sys.stdout = open("output.txt","w")
    ans = 0
    arr = []
    for i in reversed(range(N)):
        if i>=change:
            ans+=1
        arr.append(ans)
    arr = arr[::-1]
    for i in arr:
        print(i)
    exit(0)

for i in range(N):
    rnd = getNumber(1,6)
    if(rnd == 6):
        upper = getNumber(0,op)
        op+=1
        arr.append(upper)
    else:
        upper = getNumber(0,op+2)
        op=upper
        arr.append(upper)

writeArray(arr)
while connected_components > 1:
    arr = getArray(2,1,N)
    if(join(arr[0],arr[1])):
        writeArray(arr)
        connected_components -= 1

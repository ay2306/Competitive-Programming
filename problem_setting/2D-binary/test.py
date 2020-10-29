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
Q = getNumber(q_low,q_high)
arr = [N,Q]
writeArray(arr)
k = 0
while k < Q:
    arr = []
    t = getNumber(1,3)
    arr.append(t)
    if t == 2:
        i = getNumber(1,N)
        arr.append(i)
        j = getNumber(1,N)
        arr.append(j)
    if t == 3:
        i = getNumber(1,N)
        arr.append(i)
    writeArray(arr)
    k += 1
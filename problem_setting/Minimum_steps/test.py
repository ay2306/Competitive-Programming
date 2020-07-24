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

N = getNumber(n_low,n_high)
i = 0
writeNumber(N)
while i < N:
    arr = []
    a = getNumber(1,10**8)
    t = getNumber(0,3)
    if t == 0:
        arr = [a,a]
    if t == 1:
        b = getNumber(1,(10**9)//a)
        arr = [a,a*b]
    if t == 2:
        b = getNumber(1,(10**9)//a)
        arr = [b*a,a]
    if t == 3:
        arr = getArray(2,1,10**9)
    writeArray(arr)
    i+=1
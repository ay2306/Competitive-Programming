import random
def getArray(array_length,element_lower_bound,element_upper_bound):
    arr = []
    for i in range(array_length):
        arr.append(random.randint(element_lower_bound,element_upper_bound))
    return arr
def writeArray(array, file):
    for i in array:
        file.write(str(i)+" " )
    file.write('\n')
def getNumber(element_lower_bound,element_upper_bound):
    return random.randint(element_lower_bound,element_upper_bound)
def writeNumber(number, file):
    file.write(str(number) + ' ')
    file.write('\n')
def getString(arr,length):
    S = ""
    i = 0
    while i < length:
        S = S + arr[random.randint(0,len(arr)-1)]
        i = i + 1
    return S
def writeString(S,file):
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
fopen = open('input.txt','w')
t = getNumber(1,15)
writeNumber(t,fopen)
for i in range(t):
    arr = []
    n = getNumber(1,20)
    m = getNumber(1,20)
    arr.append(n)
    arr.append(m)
    writeArray(arr,fopen)
    for k in range(n):
        st = getString(['0','1'],m)
        writeString(st,fopen)
# arr = getArray(n,1,5)
# writeNumber(n,fopen)
# writeArray(arr,fopen)
# writeString(getString(smallLetters,15),fopen)
import random
import math
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
    while i < len(arr):
        S = S + arr[random.randint(0,len(arr)-1)]
        i = i + 1
    return S
def dist(x1,x2,y1,y2):
    return math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
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
x1 =getNumber(-1000,1000)
x2 =getNumber(-1000,1000)
x3 =getNumber(-1000,1000)
y1 =getNumber(-1000,1000)
y2 =getNumber(-1000,1000)
y3 =getNumber(-1000,1000)
a = dist(x1,x2,y1,y2)
b = dist(x1,x3,y1,y3)
c = dist(x3,x2,y3,y2)
arr = []
arr.append(a)
arr.append(b)
arr.append(c)
writeArray(arr,fopen)
fopen.close()
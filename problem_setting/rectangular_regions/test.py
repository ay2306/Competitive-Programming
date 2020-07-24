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
x_low = int(sys.argv[3])
x_high = int(sys.argv[4])
T = getNumber(n_low,n_high)
writeNumber(T)
op = 1
for i in range(T):    
    type = getNumber(0,5)
    arr = []
    if type <= 1:
        x1 = getNumber(x_low,x_high-5)
        y1 = getNumber(x_low,x_high-5)
        x2 = getNumber(x1+3,x_high)
        y2 = getNumber(y1+3,x_high)
        x3 = getNumber(x1+1,x2-1)
        y3 = getNumber(y1+1,y2-1)
        arr = [x1,y1,x2,y2,y1,y3]
    
    if type == 2:
        x1 = getNumber(x_low,x_high-5)
        y1 = getNumber(x_low,x_high-5)
        x2 = getNumber(x1+3,x_high)
        y2 = getNumber(y1+3,x_high)
        x3 = 1
        y3 = 1
        if op % 4 == 1:
            x3 = getNumber(x1,x1)
            y3 = getNumber(y1,y2)
        if op % 4 == 2:
            x3 = getNumber(x2,x2)
            y3 = getNumber(y1,y2)
        if op % 4 == 3:
            x3 = getNumber(x1,x2)
            y3 = getNumber(y1,y1)
        if op % 4 == 0:
            x3 = getNumber(x1,x2)
            y3 = getNumber(y2,y2)
        arr = [x1,y1,x2,y2,y1,y3]
    
    if type == 0:
        x1 = getNumber(x_low,x_high-5)
        y1 = getNumber(x_low,x_high-5)
        x2 = getNumber(x1+3,x_high)
        y2 = getNumber(y1+3,x_high)
        x3 = getNumber(x_low,x_high)
        y3 = getNumber(x_low,x_high)
        arr = [x1,y1,x2,y2,y1,y3]
    writeArray(arr)
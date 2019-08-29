import random
import sys

# sys.stdin = open("list.txt","r")

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

list = []

fopen = open('input.txt','w')
# n = getNumber(1,10**5)
n = getNumber(10,15)
m = getNumber(1,n-5)
# b = getArray(m,1,10**5)
b = getArray(m,1,10)
a = []
while len(a) < n:
    seed = getNumber(1,5)
    if seed <= 2:
        x = getNumber(1,10**5)
        if len(a) + len(b) <= n:
            k = 0
            while k < len(b):
                a.append(b[k]+x)
                k += 1
        else:
            a.append(getNumber(1,10**5))
    else:
        a.append(getNumber(1,10**5))
writeNumber(n,fopen)
writeArray(a,fopen)
writeNumber(m,fopen)
writeArray(b,fopen)
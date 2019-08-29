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
# n = getNumber(2000,10000)
# m = getNumber(1,15)
# q = getNumber(1000,1000+3000)

# # x = getNumber(1,1000)
# arr = []
# arr.append(n)
# arr.append(m)
# arr.append(q)
# writeArray(arr,fopen)
# # arr.append(x)
# # writeNumber(n,fopen)
# writeString(getString(smallLetters,n),fopen)
# writeString(getString(smallLetters,m),fopen)
# for i in range(q):
#     a = getNumber(1,n-1)
#     b = getNumber(a+1,n)
#     arr = []
#     arr.append(a)
#     arr.append(b)
#     writeArray(arr,fopen)
# arr = getArray(2*n,1,500)
# writeArray(arr,fopen)

arr = []
n = getNumber(1,2000)
m = getNumber(1,1000)
arr.append(n)
arr.append(m)
writeArray(arr,fopen)
arr = getArray(n,1,1000)
writeArray(arr,fopen)
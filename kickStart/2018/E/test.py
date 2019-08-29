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
fopen = open('input.txt','w')
n = getNumber(1,100000)
# x = getNumber(1,1000)
arr = [200000,1000000000]
# arr.append(n)
# arr.append(x)
# writeNumber(n,fopen)
writeArray(arr,fopen)
arr = []
for i in range(200000):
    arr.append(1000000000)

writeArray(arr,fopen)
# x = getNumber(-10,10)
# arr.append(x)
# t = arr[0]
# for i in range(n-1):
#     p = [-1,1]
#     x = random.randint(1,213123123)%2
#     t = t + p[x]
#     arr.append(t)
# writeArray(arr,fopen)
# writeString(getString(smallLetters,15),fopen)
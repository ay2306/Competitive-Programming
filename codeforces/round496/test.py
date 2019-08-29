import random
def getArray(array_length,element_lower_bound,element_upper_bound):
    arr = []
    for i in range(array_length):
        arr.append(random.randint(element_lower_bound,element_upper_bound))
    return arr
def writeArray(array, file):
    for i in array:
        file.write(str(i) )
    file.write('\n')
def getNumber(element_lower_bound,element_upper_bound):
    return random.randint(element_lower_bound,element_upper_bound)
def writeNumber(number, file):
    file.write(str(number) + ' ')
    file.write('\n')

fopen = open('input.txt','w')
n = getNumber(1,50)
arr = getArray(n,1,9)
# writeNumber(n,fopen)
writeArray(arr,fopen)
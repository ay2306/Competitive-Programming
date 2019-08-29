import random
def generateCase(lower_range, upperrange, times):
    arr = []
    for i in range(times):
        arr.append(random.randint(lower_range,upperrange))
    return arr

def writeToFile(arr,f):
    for i in arr:
        f.write(str(i)+' ')
    f.write('\n')
fopen = open('input.txt','w+')
n = generateCase(1,100,1)
writeToFile(n,fopen)
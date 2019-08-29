n = input()
arr = []
for i in range(n):
    tmp = []
    inp = raw_input()
    i = 1
    for e in inp.split(' '):
        if(int(e) == 1):
            tmp.append(i)
        i = i + 1
    arr.append(tmp)
garden = []
for i in len(arr):
    for j in len(arr[i]):
        tmp = []
        tmp.append(arr[i][j])
        for k in len(arr[arr[i][j]]):
            for l in len(arr[arr[arr[[i][j]]]]):
                

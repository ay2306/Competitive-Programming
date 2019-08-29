n = input()
inp = raw_input()
arr = []
a = [0,0]
for i in inp.split(' '):
    if i == '5':
        a[1] = a[1] + 1
    if i == '0':
        a[0] = a[0] + 1
p = int(arr[1]/9)
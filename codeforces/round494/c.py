inp = raw_input()
arr = []
for i in inp.split(' '):
    arr.append(int(i))
n = arr[0]
k = arr[1]
mav = 0
sum = 0
inp = raw_input()
arr = []
for i in inp.split(' '):
    arr.append(int(i))
for i in range(k):
    sum = sum+arr[i]
mav = sum/k
i = k
while i < n:
    sum = sum - arr[i-k]
    sum = sum + arr[i]
    av = sum/k
    if av > 
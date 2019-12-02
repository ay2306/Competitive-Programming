class stack:
    def __init__(self):
        self.list = []
        self.sz = 0
    def push(self,val):
        self.sz += 1
        self.list.append(val)
    def pop(self):
        self.sz -= 1
        self.list.pop()
    def size(self):
        if self.sz > 0:
            return True
        return False
    def top(self):
        return self.list[-1]
s = stack()
n = int(input())
arr = []
for i in range(n):
    a = int(input())
    arr.append(a)
ans  = [[-1,-1]]*n
ans2 = [[-1,-1]]*n
for i in range(n):
    while s.size() and arr[s.top()] < arr[i]:
        c = [s.top(),i]
        if ans[s.top()][0] != -1 and ans[s.top()][1] != -1:
            c = [ans[s.top()][0],i]
        if (c[1]-c[0] > ans[i][1]-ans[i][0]) or (c[1]-c[0] == ans[i][1]-ans[i][0] and c < ans[i]):
            ans[i] = c
        s.pop()
    s.push(i)
while s.size():
    s.pop()
for i in range(n-1,-1,-1):
    while s.size() and arr[s.top()] < arr[i]:
        c = [i,s.top()]
        if ans2[s.top()][0] != -1 and ans2[s.top()][1] != -1:
            c = [i,ans2[s.top()][1]]
        if (c[1]-c[0] > ans2[i][1]-ans2[i][0]) or (c[1]-c[0] == ans2[i][1]-ans2[i][0] and c < ans2[i]):
            ans2[i] = c
        s.pop()
    s.push(i)
prev = {}
over = [10**9]*2
for i in range(n):
    if arr[i] not in prev:
            prev[arr[i]] = i
            continue
    if i - prev[arr[i]] > over[1] - over[0]:
        over = [prev[arr[i]],i]
    elif i - prev[arr[i]] == over[1] - over[0] and prev[arr[i]] < over[0]:
        over = [prev[arr[i]],i]
    prev[arr[i]] = i
for i in range(n):
    if(ans[i][1] - ans[i][0] > over[1]-over[0]):
        over = ans[i]
    if(ans2[i][1] - ans2[i][0] > over[1]-over[0]):
        over = ans2[i]
    elif(ans2[i][1] - ans2[i][0] == over[1]-over[0] and ans2[i][0] < over[1]):
        over = ans2[i]
print(over[0]+1,over[1]+1)


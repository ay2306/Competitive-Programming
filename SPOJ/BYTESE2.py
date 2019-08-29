class priority_queue:
    def __init__(self):
        self.arr = []
    def isEmpty(self):
        return (len(self.arr) == 0)
    def insert(self,val):
        self.arr.append(val)
        parent = int((len(self.arr)-1)/2)
        current = len(self.arr)-1
        while(parent < current and self.arr[parent] > self.arr[current]):
            self.arr[parent],self.arr[current] = self.arr[current],self.arr[parent]
            current = parent
            parent = int(parent/2)
    def pop(self):
        top = self.arr[0]
        self.arr[0] = self.arr[len(self.arr)-1]
        self.arr[len(self.arr)-1] = top
        self.arr.pop()
        self.heapify(0)
    def size(self):
        return len(self.arr)
    def top(self):
        return self.arr[0]
    def heapify(self,i):
        left = 2*i+1
        N = len(self.arr)
        right = 2*i+2
        smallest = i
        if left < N and self.arr[left] < self.arr[smallest]:
            smallest = left
        if right < N and self.arr[right] < self.arr[smallest]:
            smallest = right
        if smallest != i:
            self.arr[smallest],self.arr[i] = self.arr[i],self.arr[smallest]
            self.heapify(smallest)
t = input()
for kkk in range(t):
    o = priority_queue()
    n  = input()
    ans = 0
    for i in range(n):
        inp = raw_input()
        a = int(inp.split(' ')[0])
        b = int(inp.split(' ')[1])
        while o.size() > 0 and o.top() <= a:
            o.pop()
        o.insert(b)
        if(o.size() > ans):
            ans = o.size()
    print(ans)

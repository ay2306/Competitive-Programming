import math
class segment:
    def __init__(self,n):
        self.tree = [0]*(4*n)
        self.lazy = [0]*n
        self.arr = [0]*n
        self.arr = [int(e) for e in input().split()]
        self.build(0,0,n-1)
    def build(self,node,start,end):
        if(start == end):
            self.tree[node] = self.arr[start]
            if self.tree[node] == 1:
                self.lazy[node] = 1
            return 0
        self.build(2*node+1,start,int((start+end)/2))
        self.build(2*node+2,int((start+end)/2 + 1),end)
        self.tree[node] = self.tree[2*node+1] + self.tree[2*node + 2]
        self.lazy[node] = self.lazy[2*node+1] * self.lazy[2*node + 2]
        return 0

    def update(self,node,start,end,l,r):
        if(start == end):
            self.tree[node] = int(math.sqrt(self.arr[start]))
            if self.tree[node] == 1:
                self.lazy[node] = 1
            return 0
        if self.lazy[node] == 1:
            return 0
        self.update(2*node+1,start,int((start+end)/2),l,r)
        self.update(2*node+2,int((start+end)/2 + 1),end,l,r)
        self.tree[node] = self.tree[2*node+1] + self.tree[2*node + 2]
        self.lazy[node] = self.lazy[2*node+1] * self.lazy[2*node + 2]
        return 0
    def query(self,node,start,end,l,r):
        if l > end or start > r:
            return 0
        if l <= start and end <= r:
            return self.tree[node]
        if self.lazy[node] == 1:
            return self.tree[node]
        self.p1 = self.query(2*node+1,start,int((start+end)/2),l,r)
        self.p2 = self.query(2*node+2,int((start+end)/2+1),end,l,r)
        return self.p1+self.p2


count = 1
inp = input()
while(True):
    if(len(inp.split() == 1)):
        a = segment(int(inp))
        print("Case #"+str(count)+":")
        

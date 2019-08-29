def build(tree,arr,node,start,last):
    if start == last:
        tree[node] = arr[start]
    else:
        mid = last + (start-last)/2
        tree = build(tree,arr,2*node,start,mid)
        tree = build(tree,arr,2*node + 1, mid+1, last)
        tree[node] = tree[2*node] + tree[2*node + 1]
    return tree

def update(tree, arr, node, start, last, idx, val):
    if start == last:
        tree[node] = val
    else:
        mid = last + (start-last)/2
        if start<=idx and idx <=mid:
            tree = update(tree, arr,2*node,start,mid,idx,val)
        else:
            tree = update(tree, arr,2*node+1,mid+1,last,idx,val)
        tree[node] = tree[2*node] + tree[2*node + 1]
    return tree

def query(tree, node, start, last, l, r):
    if r<start or last<l:
        return 0
    if l<=start and last<=r:
        return tree[node]
    mid = last + (start-last)/2
    p1 = query(tree,2*node,start, mid, l,r)
    p2 = query(tree,2*node + 1, mid+1, last,l, r)
    return p1+p2

def sieve(lim):
    # print "WR"
    vec = []
    ans = []
    i = 2
    while i<= lim:
        p = []
        p.append(i)
        p.append(True)
        vec.append(p)
        i = i + 1
    i = 0
    # print len(vec)
    while i < len(vec):
        tmp = False
        if(not vec[i][1]):
            i = i + 1
            continue
        j = vec[i][0]*2-2
        while j < len(vec):
            if(vec[j][1]):
                tmp = True
                vec[j][1] = False
            j = j + vec[i][0]
        if (not tmp):
            break
        i = i + 1
    i = 0
    while i < len(vec):
        if(vec[i][1]):
            ans.append(vec[i][0])
        i = i + 1
    return ans

def closestPrime(vec, num):
    if num==0 or num==1 or num==2:
        return 0
    low = 0
    high = len(vec)
    while low <= high:
        mid = low + (high - low)/2
        if vec[mid]==num:
            return vec[mid-1]
        if vec[mid-1]<=num and vec[mid]>num:
            return vec[mid-1]
        if vec[mid+1]>num and vec[mid]<num:
            return vec[mid]
        if vec[mid]>num:
            high = mid - 1
        else: 
            low = mid + 1

n = input()
q = input()
inp = raw_input()
arr = [0]
i = 1
m = 0
while i <= len(inp.split(' ')):
    arr.append(int(inp.split(' ')[i-1]))
    if m < arr[i]:
        m = arr[i]
    i = i + 1
vec = sieve(2*m)
k = n
sum = 0
while k > 0:
    sum = sum + k
    k = int(k/2)
tree = [0]
i = 1
while i <= (4*n):
    tree.append(0)
    i = i + 1
tree = build(tree,arr,1,1,n)
while q > 0:
    inp = raw_input()
    k = int(inp.split(' ')[0])
    l = int(inp.split(' ')[1])
    r = int(inp.split(' ')[2])
    if k==1:
        i = l
        while i<=r:
            tmp = arr[i]-closestPrime(vec,arr[i])
            update(tree,arr,1,1,n,i,tmp)
            arr[i] = tmp
            i = i + 1
    if k == 2:
        print (query(tree,1,1,n,l,r))
    q = q - 1
max_node = 0

def build(tree, arr, node, start, end):
    global max_node
    if node > max_node:
        max_node = node
    if start == end:
        tree[node][0] = arr[start]
        tree[node][1] = arr[start]
        return tree
    else:
        mid = int((start+end)/2)
        tree = build(tree,arr,2*node,start,mid)
        tree = build(tree,arr,2*node+1,mid+1,end)
        tree[node][0] = tree[2*node][0] * tree[2*node+1][0]
        tree[node][1] = tree[2*node][1] + tree[2*node+1][1]
        return tree

def query(tree, node, start, end, left_index, right_index):
    if(right_index < start or left_index > end):
        return [1,0]
    if(left_index <= start and  right_index >= end):
        return tree[node];
    mid = int((start+end)/2)
    p1 = query(tree, 2*node,start,mid,left_index,right_index)
    p2 = query(tree, 2*node+1,mid+1,end,left_index,right_index)
    po = []
    po.append(p1[0]*p2[0])
    po.append(p1[1]+p2[1])
    return po
inp = raw_input()
arr = []
for e in  inp.split(' '):
    arr.append(int(e))
n = arr[0]
k = arr[1]
inp = raw_input()
tree = []
for i in range(4*n):
    tree.append([1,0])
arr = []
arr.append(0)
for e in  inp.split(' '):
    arr.append(int(e))

tree = build(tree,arr,1,1,n)
l = 1
r = n
c = 0
# print tree
# print max_node
while l <= n:
    r = n
    while r >= l:
        po = query(tree,1,1,n,l,r)
        p = po[0]
        s = po[1]
        if(s*k == p):
            # print po
            c = c+1
        r = r - 1
    l = l +1    
print c
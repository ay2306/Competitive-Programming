def build_tree(tree,arr,node,start,end):
    # print node
    if start == end:
        tree[node] = arr[start]
        return tree
    else:
        mid = int((start+end)/2)
        tree = build_tree(tree,arr,2*node,start,mid)
        tree = build_tree(tree,arr,(2*node)+1,mid+1,end)
        tree[node] = tree[2*node] + tree[(2*node)+1]
        return tree
def query(tree,node,start,end,l,r):
    if(r < start or l > end):
        return 0
    if(start>=l and end<=r):
        return tree[node]
    mid = int((start+end)/2)
    p1 = query(tree,2*node,start,mid,l,r)
    p2 = query(tree,(2*node)+1,mid+1,end,l,r)
    # print p1,
    # print p2
    # print start,
    # print end
    return p1+p2

n = input()
v = []
u = []
for x in raw_input().split():
    v.append(int(x))
    u.append(int(x))
u.sort()
# print v
treeu = []
treev = []
for i in range((4*n)):
    treeu.append(0)
    treev.append(0)
treeu = build_tree(treeu,u,1,0,n-1)
treev = build_tree(treev,v,1,0,n-1)
q = input()
# print treev 
# print v
# print u
for asds in range(q):
    po = []
    for x in raw_input().split():
        po.append(int(x))
    t = po[0]
    l = po[1]
    r = po[2]
    if t == 1:
        print query(treev,1,1,n,l,r)
    if t == 2:
        print query(treeu,1,1,n,l,r)
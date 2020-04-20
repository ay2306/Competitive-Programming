#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+100;
const int LN = 15;
vector<int> g[N],cst[N],index[N];
int arr[N],ptr;
int chainNo, chainInd[N],chainHead[N],posInBase[N];
int lev[N], pa[N][LN], otherEnd[N], sub[N];
int tree[N*6], lazy[N*6];


void build(int node, int start, int end){
    if(start == end-1){
        tree[node] = arr[start];
        return;
    }
    int mid = start+end>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    tree[node] = max(tree[node<<1],tree[node<<1|1]);
}

void update(int ind, int val, int node, int start, int end){
    if(start > ind || end <= ind)return;
    if(start == ind && start == end-1){
        tree[node] = val;
        return;
    }
    int mid = start+end >> 1;
    update(ind,val,node<<1,start,mid);
    update(ind,val,node<<1|1,mid+1,end);
    tree[node] = max(tree[node << 1],tree[node<<1|1]);
}

int query(int l, int r)

int main(){e
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
class SegmentTree{
    int tree[N<<2], lazy[N<<2];
public:
    SegmentTree(){
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
    }
    void update(int id, int val, int node = 1, int start = 1, int end = N){
        if(lazy[node]){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[node<<1]^=1;
                lazy[node<<1|1]^=1;
            }
            lazy[node] = 0;
        }
        if(start == end){
            tree[node] = val;
            return;
        }
        int mid = start+end >> 1;
        if(id <= mid)update(id,val,node<<1,start,mid);
        else update(id,val,node<<1|1,mid+1,end);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    int query(int l, int r, int node = 1, int start = 1, int end = N){
        if(lazy[node]){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[node<<1]^=1;
                lazy[node<<1|1]^=1;
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return 0;
        if(l <= start && end <= r)return tree[node];
        int mid = start + end >> 1;
        int p1 = query(l,r,node<<1,start,mid);
        int p2 = query(l,r,node<<1|1,mid+1,end);
        return p1+p2;
    }
    void invert(int l, int r, int node = 1, int start = 1, int end = N){
        if(lazy[node]){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[node<<1]^=1;
                lazy[node<<1|1]^=1;
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[node<<1]^=1;
                lazy[node<<1|1]^=1;
            }
            return ;
        }
        int mid = start + end >> 1;
        invert(l,r,node<<1,start,mid);
        invert(l,r,node<<1|1,mid+1,end);
        tree[node] = tree[node<<1] + tree[node << 1 | 1];
    }
}arr[N];


struct query{
    int changes;
    int t,i,j,k;
    query(){}
}Q[100100];
int n,m,q,a,cnt = 0,qi;
void dfs(int changes = 0, int cnt = 0){
    while(qi < q){
        // printf("TYPE = %d\n",Q[qi].t);
        if(Q[qi].t == 4 && Q[qi].k == changes){
            qi++;
            cout << cnt << "\n";
            continue;
        }
        if(Q[qi].t == 4 && Q[qi].k != changes)break;
        if(Q[qi].t == 3){
            int i = Q[qi++].i;
            cnt -= arr[i].query(1,m);
            arr[i].invert(1,m);
            cnt += arr[i].query(1,m);
            cout << cnt << "\n";
            dfs(changes+1,cnt);
            cnt -= arr[i].query(1,m);
            arr[i].invert(1,m);
            cnt += arr[i].query(1,m);
            continue;
        }
        if(Q[qi].t == 2){
            int i = Q[qi].i;
            int j = Q[qi++].j;
            int init = arr[i].query(j,j);
            cnt -= init;
            arr[i].update(j,0);
            cnt += arr[i].query(j,j);
            cout << cnt << "\n";
            dfs(changes+1,cnt);
            cnt+=init;
            if(init)arr[i].update(j,1);
            continue;
        }
        if(Q[qi].t == 1){
            int i = Q[qi].i;
            int j = Q[qi++].j;
            int init = arr[i].query(j,j);
            cnt -= init;
            arr[i].update(j,1);
            cnt += arr[i].query(j,j);
            cout << cnt << "\n";
            dfs(changes+1,cnt);
            if(!init)cnt--;
            if(!init)arr[i].update(j,1);
            continue;
        }
    }
}

int main(){
    cin >> n >> m >> q;   
    for(int i = 0; i < q; ++i){
        cin >> Q[i].t;
        if(Q[i].t <= 2){
            cin >> Q[i].i >> Q[i].j; 
        }
        else if(Q[i].t == 3){
            cin >> Q[i].i; 
        }
        else if(Q[i].t == 4){
            cin >> Q[i].k; 
        }
    }
    dfs();
    return 0;
}
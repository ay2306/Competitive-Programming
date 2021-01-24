#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<pair<int,int>> tree[N*4 + 100];
vector<vector<int>> changes;
int dsu[N], parity[N];
int n,q;
int findParent(int x){
    return (dsu[x] > 0 ? findParent(dsu[x]) : x);
}
int findParity(int x){
    return (dsu[x] > 0? (parity[x] ^ findParity(dsu[x])) : 0);
}

void add_segment(int l, int r, pair<int,int> edge, int node = 1, int start = 0, int end = q-1){
    if(l > end || r < start)return;
    if(l <= start && end <= r)return void(tree[node].emplace_back(edge));
    int mid = start + end >> 1;
    add_segment(l,r,edge,node<<1,start,mid);
    add_segment(l,r,edge,node<<1|1,mid+1,end);
}

bool merge(int x, int y){
    int px = findParent(x), py = findParent(y);
    if(px != py){
        if(dsu[px] > dsu[py])swap(x,y),swap(px,py);
        changes.push_back({px,dsu[px],py,dsu[py]});
        dsu[px] += dsu[py];
        parity[py] = findParity(x)^findParity(y)^1;
        dsu[py] = px;
        return 1;
    }
    else{
        changes.push_back({});
        return findParity(x) ^ findParity(y);
    }
    return false;
}


void dfs(int node = 1, int l = 0, int r = q-1){
    bool valid = true;
    if(r < l)return;
    for(auto &i: tree[node]){
        valid &= merge(i.first,i.second);
    }
    if(valid){
        if(l != r){
            int mid = l + r >> 1;
            dfs(node << 1, l , mid);
            dfs(node << 1 | 1, mid+1, r);
        }else{
            cout << "YES\n";
        }
    }
    else{
        for(int i = l; i <= r; ++i)cout << "NO\n";
    }
    for(int i = 0; i < tree[node].size(); ++i){
        if(changes.back().size()){
            auto &c = changes.back();
            dsu[c[0]] = c[1];
            dsu[c[2]] = c[3];
        }
        changes.pop_back();
    }
}

int main(){
    scanf("%d%d",&n,&q);
    memset(dsu,-1,sizeof(dsu));
    {
        map<pair<int,int>,int> indexing;
        for(int i = 0; i < q; ++i){
            pair<int,int> x;
            scanf("%d%d",&x.first,&x.second);
            if(x.first > x.second)swap(x.first,x.second);
            if(indexing.count(x) == 0)indexing[x] = i;
            else{
                add_segment(indexing[x],i-1,x);
                indexing.erase(x);
            }
        }
        for(auto &i: indexing)add_segment(i.second,q-1,i.first);
    }
    dfs();
    return 0;
}
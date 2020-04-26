#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int tree[N<<2];

void update(int index, int val, int node = 0, int start = 0, int end = N-1){
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    if(index <= mid)update(index,val,2*node+1,start,mid);
    if(index > mid)update(index,val,2*node+2,mid+1,end);
    tree[node] = __gcd(tree[node*2 + 2],tree[node*2 + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int,vector<int>> m;
    m.reserve(1<<12);
    m.max_load_factor(0.25);
    int n,a; char c;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c >> a;
        if(c == '-'){
            update(m[a].back(),0);
            m[a].pop_back();
        }
        else{
            m[a].emplace_back(i);
            update(i,a);
        }
        printf("%d\n",max(tree[0],1));
    }
    return 0;
}
#include <bits/stdc++.h>
#define V vector
using namespace std;
 
V<int> first;
V<int> arr;
V<V<int> > adj;
V<int> height;
V<int> hs;
V<int> tree;
int n;
void dfs(int s, int p){
    arr.push_back(s);
    if(p != -1)height[s] = height[p]+1;
    for(auto i: adj[s]){
        if(i == p)continue;
        dfs(i,s);
        arr.push_back(s);
    }
}
 
void build(int node = 0, int start = 0, int end = arr.size()-1){
    if(start == end){
        tree[node] = start;
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    tree[node] = (hs[tree[2*node+1]] < hs[tree[2*node+2]])?tree[2*node+1]:tree[2*node+2];
   
}
 
int query(int l, int r, int node = 0, int start = 0, int end = arr.size()-1){
    if(start > r|| end < l)return -1;
    if(l <= start && end <= r)return tree[node];
    int p1 = query(l,r,2*node+1,start,(start+end)/2);
    int p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return (hs[p1] < hs[p2])?p1:p2;
}
 
int main() {
    cin >> n;
    adj = V<V<int> > (n, V<int>());
    height = V<int> (n,0);
    first = V<int> (n,-1);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        while(a--){
            int b;
            cin >> b;
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }
    dfs(0,-1);
    for(int i = 0; i < arr.size(); ++i){
        int k = arr[i];
        if(first[k] == -1)first[k] = i;
    }
    // printf("ARR: ");
    // for(auto i: arr)cout << i << " ";
    // printf("\n");
    // printf("First: ");
    // for(auto i: first)cout << i << " ";
    // printf("\n");
    for(int i = 0; i < arr.size(); ++i){
        hs.push_back(height[arr[i]]);    
    }
    tree = V<int> (4*hs.size());
    build();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a = first[a];
        b = first[b];
        if(a > b)swap(a,b);
        int ans = query(a,b);
        cout << arr[ans] << "\n";
    }
    return 0;
}

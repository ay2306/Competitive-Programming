//https://codeforces.com/contest/707/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,q,ans[N*100];

bitset<N> arr[N],aux;
struct query{
    int type;
    int row;
    int col;
    query():type(0),row(0),col(0){}
}ar[N*100];

vector<int> g[N*100];

void dfs(int node, int res = 0){
    if(ar[node].type == 1){
        int init = arr[ar[node].row][ar[node].col];
        arr[ar[node].row][ar[node].col] = 1;
        if(!init)res++;
        ans[node] = res;
        for(int &i : g[node])dfs(i,res);
        if(!init)arr[ar[node].row][ar[node].col] = 0;
        return;
    }
    if(ar[node].type == 2){
        int init = arr[ar[node].row][ar[node].col];
        arr[ar[node].row][ar[node].col] = 0;
        if(init)res--;
        ans[node] = res;
        for(int &i : g[node])dfs(i,res);
        if(init)arr[ar[node].row][ar[node].col] = 1;
        return;
    }
    if(ar[node].type == 3){
        res-=arr[ar[node].row].count();
        arr[ar[node].row] = ~arr[ar[node].row];
        arr[ar[node].row]&=aux;
        res+=arr[ar[node].row].count();
        ans[node] = res;
        for(int &i : g[node])dfs(i,res);
        arr[ar[node].row] = ~arr[ar[node].row];
        arr[ar[node].row]&=aux;
        return;
    }
    ans[node] = res;
    for(int &i : g[node])dfs(i,res);
}

int main(){
    cin >> n >> m >> q;   
    for(int i = 1; i <= m; ++i)aux[i] = 1;
    for(int i = 1; i <= q; ++i){
        int a,b,c;
        cin >> a;
        ar[i].type = a;
        if(a == 4){
            cin >> c;
            g[c].emplace_back(i);
        }
        else if(a == 3){
            cin >> ar[i].row;
            g[i-1].emplace_back(i);
        }
        else{
            cin >> ar[i].row >> ar[i].col;
            g[i-1].emplace_back(i);
        }
    }
    dfs(0);
    for(int i = 1; i <= q; ++i)cout << ans[i] << "\n";
    return 0;
}
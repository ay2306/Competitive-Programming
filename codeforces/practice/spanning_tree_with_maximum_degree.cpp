//https://codeforces.com/contest/1133/problem/F1
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int p[N],deg[N],n,a,b,m,mx;
vector<pair<int,int>> edges,answer;
int f(int x){
    if(p[x] != x)p[x] = f(p[x]);
    return p[x];
}
void u(int a, int b){
    p[f(a)] = f(b);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; ++i)p[i] = i;
    for(int i = 0 ;i < m; ++i){
        scanf("%d %d",&a,&b);
        edges.emplace_back(a,b);
        deg[a]++;
        deg[b]++;
        deg[mx] < deg[a] ? mx = a: 0;
        deg[mx] < deg[b] ? mx = b: 0;
    }
    sort(edges.begin(),edges.end(),[](const pair<int,int> &a, const pair<int,int> &b)->bool{
        return !(b.first == mx || b.second == mx);
    });
    for(auto &i: edges){
        if(f(i.first) != f(i.second))answer.emplace_back(i),u(i.first,i.second);
    }
    for(auto &i: answer)printf("%d %d\n",i.first,i.second);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> p,ans,h;
set<int> h1;
int f(int x){p[x]==x?x:p[x]=f(p[x]);return p[x];}
void u(int a, int b){p[f(a)] = f(b);}
int n,s,m,a,b;
int main(){
    scanf("%d%d",&n,&m);
    vector<pair<int,int>>q(m);
    p.resize(n+1);
    for(int i = 0; i <= n; ++i)p[i] = i;
    for(auto &i: q)scanf("%d%d",&i.first,&i.second);
    scanf("%d",&s);
    for(int i = 0; i < s; ++i){
        scanf("%d",&a);
        h1.insert(a-1),h.emplace_back(a-1);
    }
    int cur = n;
    ans.resize(s);
    for(int i = 0; i < m; ++i){
        if(h1.count(i))continue;
        if(f(q[i].first) != f(q[i].second)){
            u(q[i].first,q[i].second);
            cur--;
        }
    }
    for(int i = s-1; i >= 0; --i){
        ans[i] = cur;
        if(f(q[h[i]].first) != f(q[h[i]].second)){
            cur--;
            u(q[h[i]].first,q[h[i]].second);
        }
    }
    for(int &i : ans)printf("%d ",i);
    return 0;
}
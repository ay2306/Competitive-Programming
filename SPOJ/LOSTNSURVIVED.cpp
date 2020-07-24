#include<bits/stdc++.h>
const int N = 2e5;
int p[N],q,n,a,b;
std::multiset<int> m;

int f(int x){
    if(p[x] < 0)return x;
    p[x] = f(p[x]);
    return p[x];
}

void join(int a, int b){
    a = f(a);
    b = f(b);
    if(a == b)return;
    auto it = m.find(-p[a]);
    m.erase(it);
    it = m.find(-p[b]);
    m.erase(it);
    p[a]+=p[b];
    p[b] = a;
    m.emplace(-p[a]);
}

int main(){
    std::memset(p,-1,sizeof(p));
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; ++i)m.emplace(1);
    while(q--){
        scanf("%d%d",&a,&b);
        join(a,b);
        printf("%d\n",*prev(m.end())-*m.begin());
    }
    return 0;
}

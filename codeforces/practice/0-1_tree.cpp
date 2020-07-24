//https://codeforces.com/problemset/problem/1156/D
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
vector<pair<int,int>> edges;
int n,a,b,c,p[N];
long long ans;

class dsu{
    int p[N];
public:
    dsu(){memset(p,-1,sizeof(p));}
    int f(int x){
        if(p[x] < 0)return x;
        p[x] = f(p[x]);
        return p[x];
    }
    void join(int a, int b){
        a = f(a);
        b = f(b);
        if(a == b)return;
        p[a]+=p[b];
        p[b] = a;
    }
    int size(int a){
        return -p[f(a)];
    }
};

int main(){
    scanf("%d",&n);
    dsu z,o;
    for(int i = 1; i < n; ++i){
        scanf("%d%d%d",&a,&b,&c);
        if(c)o.join(a,b);
        else z.join(a,b);
    }
    unordered_map<int,vector<int>> m;
    for(int i = 1; i <= n; ++i)m[o.f(i)].emplace_back(i);
    for(auto &i: m){
        long long zero = 0, ones = o.size(i.first);
        for(auto &j: i.second)zero+=z.size(j)-1;
        ans += zero*ones;
        ans += ones*ones;
        ans -= ones;
    }
    return printf("%lld\n",ans),0;
}
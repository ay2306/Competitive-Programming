#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    scanf("%d",&n);
    vector<int> p(n+1);
    iota(p.begin(),p.end(),0);
    function<int(int)> findParent = [&](int x)->int{
        if(p[x] != x)p[x] = findParent(p[x]);
        return p[x];
    };
    auto join = [&](int a, int b)->void{
        p[findParent(a)] = findParent(b);
    };
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a);
        join(i,a);
    }
    map<int,int> m;
    for(int i = 1; i <= n; ++i)m[findParent(i)]++;
    int ans = 1;
    for(auto i: m){
        ans = ans/__gcd(ans,i.second)*i.second;
    }
    printf("%d",ans);
    return 0;
}
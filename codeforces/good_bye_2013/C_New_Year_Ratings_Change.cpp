#include<bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int,int>> s;
    int n,a;
    scanf("%d",&n);
    map<int,int> p;
    function<int(int)> f = [&](int x)->int{
        if(p[x] == x)return x;
        p[x] = f(p[x]);
        return p[x];
    };
    auto join = [&](int i, int j){
        i = f(i);
        j = f(j);
        if(i > j)swap(i,j);
        p[i] = j;
    };
    auto create = [&](int x){
        if(p.count(x) == 0)p[x] = x;
    };
    vector<int> ar(n);
    for(int &i: ar)scanf("%d",&i);
    for(int i: ar){
        create(i);
        int ans = f(i);
        printf("%d ",ans);
        create(ans+1);
        join(ans,ans+1);
    }
    return 0;
}
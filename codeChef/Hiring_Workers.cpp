#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int p[N];

void solve(){
    int k,x;
    scanf("%d%d",&k,&x);
    vector<int> f;
    while(x > 1){
        int j = 1, r = p[x];
        while(x%r == 0){
            x/=r;
            j*=r;
        }
        f.emplace_back(j);
    }
    if(k >= f.size())return void(printf("%d\n",accumulate(f.begin(),f.end(),0)+k-f.size()));
    int ans = accumulate(f.begin(),f.end(),0);
    set<int> s;
    for(auto i : f)s.emplace(i);
    while(s.size() > k){
        int a = *s.begin();
        s.erase(s.begin());
        int b = *s.begin();
        s.erase(s.begin());
        int change = a*b - a - b;
        s.insert(a*b);
        ans += change;
    }
    printf("%d\n",ans);
}

int main(){
    for(int i = 2; i < N; ++i){
        if(p[i] != 0)continue;
        for(int j = i; j < N; j+=i)p[j] = i;
    }
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
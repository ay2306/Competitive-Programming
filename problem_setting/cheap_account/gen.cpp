#include<bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}
int parseInt(char *a){
    int s = 0;
    for(int i = 0; a[i] != '\0'; ++i)s = s*10 + a[i] - '0';
    return s;
}

int32_t main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int q = getRandom(1,10000);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    int m = getRandom(1,min(200000LL,n*(n-1)/2));
    cout << n << " " << m << "\n";
    int chigh = 1e5;
    if(n <= 6)chigh = 15;
    for(int i = 0; i < n; ++i)cout << getRandom(1,chigh) << " ";
    cout << "\n";
    vector<int> p(n+1);
    iota(p.begin(),p.end(),0);
    function<int(int)> fp = [&](int x)->int{
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    };
    auto u = [&](int a, int b){
        p[fp(a)] = fp(b);
    };
    while(m){
        int x,y,z;
        x = getRandom(1,n-1);
        y = getRandom(x+1,n);
        if(fp(x) != fp(y)){
            cout << x << " " << y << " " << getRandom(1,chigh) << "\n";
            m--;
        }
    }
    return 0;
}

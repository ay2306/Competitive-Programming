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
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    int m = getRandom(1,min(200000LL,n*(n-1)));
    if(n <= 4)m = min(n*(n-1),getRandom(1,6));
    cout << n << " " << m << "\n";
    vector<set<int>> g(n+1);
    while(true){
	    if(m == 0)break;
    	int a = getRandom(1,n-1);
        int b = getRandom(a+1,n);
        if(getRandom(1,123)&1)swap(a,b);
        if(g[a].count(b))continue;
    	m--;
	    cout << a << " " << b << "\n";
        g[a].emplace(b);
    }
    int q = getRandom(1,100000);
    if(n <= 6)q = getRandom(3,5);
    q = min(n*(n-1),q);
    cout << q << "\n";
    while(q--){
        int a = getRandom(1,n-1);
        int b = getRandom(a+1,n);
        if(getRandom(1,123)&1)swap(a,b);
	    cout << a << " " << b << "\n";
    }
    return 0;
}

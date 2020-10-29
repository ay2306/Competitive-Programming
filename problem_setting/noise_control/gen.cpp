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
    int m = getRandom(1,n);
    int k = getRandom(1,n*m);
    cout << n << " " << m << " " << k << "\n";
    int lim = 1e4;
    if(n <= 5)lim = 10;
    //noise
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j)cout << getRandom(1,lim) << " ";
	cout << endl;
    }
    if(n <= 5)lim = 3;
    //thres
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j)cout << getRandom(1,lim*getRandom(1,n*m)) << " ";
	cout << endl;
    }
    set<pair<int,int>> s;
    while(s.size() < k){
    	pair<int,int> a(getRandom(1,n),getRandom(1,m));
        if(s.count(a) == 0){
            s.emplace(a);
            cout << a.first << " " << a.second << "\n";
        }
    }
    return 0;
}

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
    int t = getRandom(100,100000);
    if(n <= 6){
        t = getRandom(1,1);
        cout << t << "\n";
    }else{
        cout << t << "\n";
        cout << "10000000000000000000\n";
        t--;
    }
    for(int i = 0 ; i < t; ++i){
        if(n <= 6)cout << getRandom(1,3) << "\n";
        else cout << getRandom(n_low,n_high) << "\n";	
    }
    return 0;
}

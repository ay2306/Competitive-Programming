#include<bits/stdc++.h>
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

int main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int q = getRandom(1,10000);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    cout << n << "\n";
    for(int i = 0 ; i < n; ++i){
        if(n <= 10)cout << getRandom(1,5) << " ";
        else cout << getRandom(1,1000000) << " ";	
    }
    return 0;
}

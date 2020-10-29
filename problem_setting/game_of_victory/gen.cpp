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
    int test = getRandom(1,100000);
    if(n_high <= 3)test = 1;
    cout << test << "\n";
    while(test--){
        int yes = getRandom(0,1);
        if(yes){
            int n = getRandom(n_low,n_high);
            cout << n*n << "\n";
        }else{
            int n = getRandom(n_low,n_high*n_high);
            cout << n << "\n";
        }
    }
    return 0;

}

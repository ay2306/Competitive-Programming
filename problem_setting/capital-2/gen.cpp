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

string getString(int len){
    string s = "";
    while(len--){
        int a = getRandom(1,8);
        if(a <= 3){
            s+=char(getRandom('A','Z'));
        }
        else if(a <= 6){
            s+=char(getRandom('a','z'));
        }
        else if(a <= 8){
            s+=' ';
        }
    }
    return s;
}

int32_t main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int q = getRandom(1,10000);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    cout << getString(n);
    return 0;
}

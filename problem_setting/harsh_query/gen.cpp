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

string getRandomString(int len){
    string ans = "";
    while(len--){
        ans += char(getRandom(0,25)+'a');
    }
    return ans;
}

int32_t main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    int q = getRandom(1,500000);
    if(n <= 5)q = getRandom(2,4);
    cout << q << "\n" << getRandomString(n) << "\n";
    while(q--){
        int l = getRandom(1,n);
        int r = getRandom(l,n);
        cout << l << " " << r << "\n";
    }
    return 0;
}

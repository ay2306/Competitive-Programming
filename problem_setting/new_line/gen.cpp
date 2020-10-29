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
    string ans = "";
    while(len--){
        ans += char(getRandom('a','z'));
    }
    return ans;
}

int32_t main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int q = getRandom(1,10000);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    vector<string> arr;
    while(n){
        int len = getRandom(1,n);
        n-=len;
        arr.emplace_back(getString(len));
    }
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i];
        if(i+1 != arr.size())cout << " ";
    }
    return 0;
}

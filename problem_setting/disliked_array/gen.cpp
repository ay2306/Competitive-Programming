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
    int test = 5;
    int chigh = 100;
    if(n_high <= 6)test=1,chigh = 15;
    cout << test << "\n";
    while(test--){
        int ans = getRandom(0,1);
        int n = getRandom(n_low,n_high);
        cout << n << "\n";
        vector<int> arr;
        for(int i = 0; i < n; ++i)arr.emplace_back(getRandom(0,chigh));
        if(ans == 1){
            int f = getRandom(0,1)*2 - 1;
            for(auto &i: arr)i = f*(abs(i));
        }else{
            for(auto &i: arr){  
                int f = getRandom(0,1)*2 - 1;
                i = f*(abs(i));
            }
        }
        for(int i : arr)cout << i << " ";
        cout << "\n";
    }
    return 0;
}

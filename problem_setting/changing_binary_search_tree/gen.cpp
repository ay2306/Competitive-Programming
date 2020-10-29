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
    int chigh = 1e6;
    if(n <= 6)chigh = 15;
    cout << n << "\n";
    set<int> s;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i){
        do{
            arr[i] = getRandom(1,chigh);
        }while(s.count(arr[i]));
        cout << arr[i];
        if(i < n)cout << " ";
        else cout << "\n";
        s.emplace(arr[i]);
    }
    int q = getRandom(1,(int)1e5);
    if(n <= 6)q = getRandom(2,4);
    cout << q << "\n";
    while(q--){
        int i = getRandom(1,n);
        int newVal;
        do{
            newVal = getRandom(1,chigh);
        }while(s.count(newVal));
        cout << i << " " << newVal-arr[i] << "\n";
        s.erase(arr[i]);
        arr[i] = newVal;
        s.emplace(arr[i]);
    }
    return 0;
}

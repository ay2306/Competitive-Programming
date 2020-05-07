#include<bits/stdc++.h>
using namespace std;
int q;
int findLargest(int lo, int hi){
    int ans = lo;
    while(lo <= hi){
        int mi = lo + hi >> 1;
        cout << "> " << mi << endl;
        int val;
        cin >> val;
        q++;
        if(val == 1){
            lo = mi+1;
        }else{
            ans = mi;
            hi = mi-1;
        }
    }
    return ans;
}

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    if(n < 60){
        int mn = INT_MAX;
        int mx = 0;
        for(int i = 1; i <= n; ++i){
            cout << "? " << i << endl;
            int a;
            cin >> a;
            mn = min(a,mn);
            mx = max(a,mx);
        }
        cout << "! " << mn << " " << (mx-mn)/(n-1) << endl;
        return 0;
    }
    int mx = findLargest(0,(int)1e9);
    int d = 0;
    for(int i = 1; i < 60 && q < 60; q++,i++){
        cout << "? " << rng()%n+1 << endl;
        int a;
        cin >> a;
        d = __gcd(d,mx-a);
    }
    cout << "! " <<  mx-(n-1)*d << " " << d << endl;
    return 0; 
}
#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int s = 0;
    int leap = (n%4 == 0 && (n%100 || (n%400 == 0)));
    int cur_leap = leap;
    do{
        s+=365;
        if(n % 4 == 0){
            if(n%100 || (n%400 == 0))s++;
        }
        s%=7;
        n++;
        cur_leap = (n%4 == 0 && (n%100 || (n%400 == 0)));
    }while(s || cur_leap != leap);
    cout << n ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
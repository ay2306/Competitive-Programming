#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}


int cal(int mod, string &a){
    reverse(a.begin(),a.end());
    int t_mod = 1;
    int val = 0;
    for(int i = 0; i < a.size(); ++i){
        int digit = ((a[i]-'0')*t_mod)%mod;
        val+=digit;
        val%=mod;
        t_mod*=10;
        t_mod%=mod;
    }
    return val;
}

void solve(){
    int a;
    string b;
    cin >> a >> b;
    if(a == 0){
        cout << b << "\n";
        return;
    }
    if(b == "0"){
        cout << a << "\n";
        return;
    }
    cout << gcd(a,cal(a,b)) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
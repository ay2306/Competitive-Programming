#include<bits/stdc++.h>
#define ull unsigned long long int
#define mod 1000000007
using namespace std;

ull p(ull a, ull b){
    if(b == 0)return 1;
    if(b == 1)return a%mod;
    if(b == 2){
        return ((a%mod)*(a%mod))%mod;
    }
    if(b == 3){
        return ((((a%mod)*(a%mod))%mod)*(a%mod))%mod;
    }
    if(b%2 == 0){
        a = ((a%mod) * (a%mod))%mod;
        return p(a,b/2)%mod;
    }else{
        return ((a%mod)*(p(a,b-1)%mod))%mod;
    }
}


void solve(){
    ull n;
    cin >> n;
    if(n == 1){
        cout << "2\n";
        return;
    }
    if(n == 2){
        cout << "4\n";
        return;
    }
    if(n%2 == 1){
        cout << ((2%mod)*(p(3,n/2)%mod))%mod << endl;
    }
    if(n%2 == 0){
        cout << ((4%mod)*(p(3,n/2)%mod))%mod << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
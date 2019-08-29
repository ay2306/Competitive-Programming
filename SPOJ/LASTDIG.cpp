#include <bits/stdc++.h>
#define ll long long int

const ll mod = 10;

int power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    int p = power(a,n/2);
    p*=p;
    if(n%2)p*=a;
    return p%mod;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        ll a,b;
        std::cin >> a >> b;
        std::cout << power(a,b) << "\n";
    }
   return 0;
}
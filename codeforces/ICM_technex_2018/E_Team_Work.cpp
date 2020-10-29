#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9+7;

int power(int a, int n){
    if(a == 1 || n == 0)return 1;
    if(n == 1)return a;
    int p = power(a,n>>1);
    p = p * p % mod;
    if (n & 1)p = p * a % mod;
    return p;
}

int facr

int32_t main(){
    int ans = 0;
    int n,k;
    cin >> n >> k;

    for(int choosen = 1; choosen <= n; ++choosen){

    }
    return 0;
}
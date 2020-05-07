//https://codeforces.com/contest/7/problem/D
#include<bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define hash abcdef
const long long int special_prime = 982451653;
const long long int mod = 1e9+7;
const int N = 5e6 + 10;
using namespace std;
long long dp[N],hash[N],power[N],power_inv[N],reverse_hash[N],prime_inverse;
int n;

long long modular_exponentiation(long long a, long long n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    long long p = modular_exponentiation(a,n>>1);
    p *= p;
    p %= mod;
    if(n & 1)p *= a;
    p %= mod;
    return p;
}

void pre(string &a){
    power[0] = 1;
    power_inv[0] = 1;
    prime_inverse = modular_exponentiation(special_prime,mod-2);
    for(int i = 1; i < N; ++i){
        power[i] = power[i-1]*special_prime%mod;
        power_inv[i] = power_inv[i-1]*prime_inverse%mod;
    }
    for(int i = 0; i < n; ++i){
        hash[i] = power[i]*a[i]%mod;
        if(i)hash[i] += hash[i-1];
        hash[i] %= mod;
        reverse_hash[n-1-i] = power[i]*a[n-1-i]%mod;
        if(i)reverse_hash[n-1-i] +=  reverse_hash[n-i];
        reverse_hash[n-1-i] %= mod;
    }
}

long long int subHash(int l, int r){
    long long int res = hash[r];
    if(l)res = (res-hash[l-1]+mod)%mod;
    res *= power_inv[l];
    res %= mod;
    return res;
}

long long int ReverseSubHash(int l, int r){
    long long int res = reverse_hash[l];
    if(r+1 < n)res = (res-reverse_hash[r+1]+mod)%mod;
    int inverted_radix = n-1-r;
    res *= power_inv[inverted_radix];
    res %= mod;
    return res;
}

bool isPalindrome(int l, int r){
    int length = r-l+1 >> 1;
    long long left = subHash(l,l+length-1);
    long long right = ReverseSubHash(r-length+1,r);
    return left == right;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin >> a;
    n = a.size();
    pre(a);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(isPalindrome(0,i))dp[i]=dp[(i-1)/2]+1;
    }
    long long res = accumulate(dp,dp+N,0LL);
    return printf("%lld\n",res),0;
}
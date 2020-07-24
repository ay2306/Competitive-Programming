//https://codeforces.com/contest/487/problem/C
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    if(!(x&1) && x != 2)return false;
    for(int i = 3; i*i <= x; ++i)if(x%i == 0)return false;
    return true;
}

long long power(long long a, long long n, long long mod){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    long long p = power(a,n>>1,mod);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

int main(){
    int n;
    cin >> n;
    if(n == 1)return cout << "YES\n1",0;
    if(n == 4)return cout << "YES\n1\n3\n2\n4",0;
    if(!isPrime(n))return cout << "NO",0;
    int cur = 1;
    cout << "YES\n";
    for(int i = 1; i < n; ++i){
        cur = power(cur,n-2,n) * i % n;
        cout << cur << "\n";
        cur = i;
    }
    cout << n;
    return 0;
}
// Euler Toitent -> Phi(n) = Number of i in range(1,n) such that __gcd(i,n) = 1

// 1. For a prime number P, Phi(P) = P-1
// 2. For a number X => P^K - (P^K)/P -> P^K - P^(K-1)  
// 3. A,B such that __gcd(A,B) = 1, Phi(A*B) = Phi(A) * Phi(B)
// 4. X -> P1^K1 * P2^K2 * ...

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin >> x;
    n = x;
    vector<pair<int,int>> factors;
    for(int i = 2; i*1LL*i <= x; ++i){
        if(n % i)continue;
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n/=i;
        }
        factors.emplace_back(i,cnt);
    }
    long long ans = 1;
    function<long long(long long, long long)> power = [&](long long a, long long n)->long long{
        if(n == 0 || a == 1)return 1;
        if(n == 1)return a;
        long long p = power(a,n/2);
        p = p * p;
        if(n & 1)p *= a;
        return p;
    };
    for(auto i: factors)ans*=(power(i.first,i.second) - power(i.first,i.second-1));
    cout << ans << "\n";
    return 0;
}
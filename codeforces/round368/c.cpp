//https://codeforces.com/contest/707/problem/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void twomn(ll k){
    for(ll i = 1; i*i <= (k>>1); ++i){
        if((k>>i)%i)continue;
        ll m = i;
        ll n = (k>>i)/m;
        ll a = m*m + n*n;
        ll b = abs(m*m - n*n);
        ll c = 2*m*n;
        if(b*b+c*c == a*a){
            if(a == k)swap(a,c);
            if(b == k)swap(b,c);
            swap(a,b);
            cout << a << " " << b;
            exit(0);
        }
    }
}

int main(){
    ll a,b,c,m,n;
    cin >> a;
    if(a <= 2){
        return cout << -1 << "\n",0;
    }
    if(a%2 == 0)twomn(a);
    if(a % 2 == 1){
        ll m = a/2+1;
        ll n = a/2;
        ll k = a;
        ll a = m*m + n*n;
        ll b = m*m - n*n;
        ll c = 2*m*n;
        if(b*b+c*c == a*a){
            if(a == k)swap(a,c);
            if(b == k)swap(b,c);
            swap(a,b);
            cout << a << " " << b;
            exit(0);
        }
        return 0;
    }
    if(a % 4 == 0){
        cout << (a/4)*3 << " " << (a/4)*5;
        return 0;
    }
    return cout << -1 << "\n",0;
}
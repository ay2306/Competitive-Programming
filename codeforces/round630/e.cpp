//https://codeforces.com/problemset/problem/1332/E
#include <bits/stdc++.h>
#define MOD 99824435
#define ll long long int
using namespace std;

ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%MOD;
	ll p = power(a,n/2);
	p=p*p%MOD;
	if(n&1)p=p*a%MOD;
	return p;
}

int main(){
	ll n,m,l,r,k,x;
	cin >> n >> m >> l >> r;
	k = n*m;
	x = r-l+1;
	if(x % 2){
		return cout << power(x,k),0; 
	}
	cout << (power(x,k)+x%2LL)*power(2,MOD-2)%MOD;
	return 0;
}

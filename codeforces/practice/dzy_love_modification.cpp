#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3+100;
const int M = 1e6+100;
ll a[N][N],rm[M],cm[M];
int main(){
	int n,m,k;
	ll p;
	scanf("%d%d%d%lld",&n,&m,&k,&p);
	// int helloworld;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	multiset<ll,greater<ll>> r,c;
	for(int i = 0; i < n; ++i){
		ll s = 0;
		for(int j = 0; j < m; ++j)s+=a[i][j];
		r.insert(s);
	}
	for(int i = 0; i < m; ++i){
		ll s = 0;
		for(int j = 0; j < n; ++j)s+=a[j][i];
		c.insert(s);
	}
	for(int i = 1; i <= k; ++i){
		rm[i] = rm[i-1] + *r.begin();
		// ll x = *r.begin() - m*p;
		r.erase(r.begin());
		r.insert(rm[i]-rm[i-1]-m*p);
	}
	for(int i = 1; i <= k; ++i){
		cm[i] = cm[i-1] + *c.begin();
		c.erase(c.begin());
		c.insert(cm[i]-cm[i-1]-n*p);
	}
	ll op = LLONG_MIN;
	for(int i = 0; i <= k; ++i)op=max(op,cm[i]+rm[k-i]-i*1LL*(k-i)*p);
	printf("%lld\n",op);
}
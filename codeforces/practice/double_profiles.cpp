#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10,mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(){
	uniform_int_distribution<long long> uid(0,(1LL<<62)-1);
	return uid(rng);
}

vector<int> g[N];
int n, m, a, b;
long long hashed[N],HASH[N],ans,cnt;



int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d",&a,&b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for(int i = 1; i <= n; ++i)
		HASH[i] = rnd();
	for(int i = 1; i <= n; ++i)
		for(int j : g[i])hashed[i]^=HASH[j];
	map<long long,long long> m;
	for(int i = 1; i <= n; ++i){
		ans+=m[hashed[i]];
		m[hashed[i]]++;
		for(int j: g[i])
			cnt+= ((hashed[i] ^ HASH[j]) == (hashed[j] ^ HASH[i]));
	}
	ans+=(cnt/2);
	return printf("%lld\n",ans),0;
}
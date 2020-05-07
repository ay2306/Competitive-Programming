#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,m,s1 = 0,s2 = 0,a,t,l,r,q;
		scanf("%lld%lld",&n,&m);
		for(int i = 0; i < n; ++i){
			scanf("%lld",&a);
			s1 = (s1 + a + mod)%mod;
		}
		for(int i = 0; i < m; ++i){
			scanf("%lld",&a);
			s2 = (s2 + a + mod)%mod;
		}
		scanf("%lld",&q);
		while(q--){
			scanf("%lld",&t);
			if(t == 3)printf("%lld\n",s1*s2%mod);
			else{
				scanf("%lld%lld%lld",&l,&r,&a);
				if(t == 1){
					if(a < 0)a+=mod;
					s1 = (s1 + a*(r-l+1)%mod + mod)%mod;
				}
				else{
					if(a < 0)a+=mod;
					s2 = (s2 + a*(r-l+1)%mod + mod)%mod;
				}
			}
		}
	}
	
	return 0;
}
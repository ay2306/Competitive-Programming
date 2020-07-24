#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
vector<int> g[N];
int dis[N];
queue<int> q;

int main(){
	function<bool(int)> isPrime = [](int x)->bool{
		for(int i = 2; i*i <= x; ++i)if(x%i == 0)return false;
		return true;
	};
	function<int(int,int)> gap = [](int a, int b)->int{
		int ans = 0;
		while(a){
			ans += (a%10 != b%10);
			a/=10;
			b/=10;
		}
		return ans;
	};
	vector<int> primes;
	for(int  i = 1000; i <= 9999; ++i){
		if(isPrime(i)){
			for(int j: primes){
				if(gap(i,j) > 1)continue;
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}
			primes.emplace_back(i);
		}
	}
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		memset(dis,-1,sizeof(dis));
		dis[a] = 0;
		q.push(a);
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v: g[u]){
				if(dis[v] == -1){
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}		
		if(~dis[b])printf("%d\n",dis[b]);
		else printf("Impossible\n");
	}
	return 0;
}

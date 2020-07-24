#include<bits/stdc++.h>
#define float long double
#define int long long
using namespace std;
const int32_t N = 1010;
int n,l;
float x[N], dis[N], b[N], store[N][N], g[N][N];
bool vis[N];
float minDis(int u){
	if(u == n)return 0;
	if(vis[u])return dis[u];
	vis[u] = true;
	float &ans = dis[u];
	ans = 1e9;
	for(int v = u + 1; v <= n; ++v)ans = min(ans,g[u][v]+minDis(v));
	return ans;
}

void path(int u){
	if(u == n)return;
	for(int v = u + 1; v <= n; ++v){
		if(dis[u] == g[u][v] + dis[v]){
			cout << v << " ";
			path(v);
			return;
		}
	}
}

bool check(float k, bool print){
	for(int i = 0; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			g[i][j] = store[i][j] - k * b[j];
	memset(vis,0,sizeof(vis));
	float mx = minDis(0);
	if(print)path(0);
	return mx <= 0;
}

int32_t main(){
	cin >> n >> l; 
	for(int i = 1; i <= n; ++i)cin >> x[i] >> b[i];
	for(int i = 0; i <= n; ++i){
		for(int j = i+1; j <= n; ++j){
			store[i][j] =  sqrtl(abs(x[j]-x[i]-l));
		}
	}
	float lo = 0, hi = 1e9;
	for(int i = 0; i <= 100; ++i){
		float mid = (lo+hi)/2;
		if(check(mid,0))hi=mid;
		else lo = mid;
	}
	check(lo,1);
	return 0;
}

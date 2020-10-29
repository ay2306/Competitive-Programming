#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int i,j,w;
	node(){}
	node(int i, int j, int w):i(i),j(j),w(w){}
	bool operator<(const node& r)const{
		return w < r.w;
	}
	bool operator>(const node& r)const{
		return w > r.w;
	}
	bool operator==(const node& r)const{
		return w == r.w;
	}
};

int32_t main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> indi(n,vector<int>(m,0));
	vector<vector<int>> dis(n,vector<int>(m,1e15));
	vector<vector<int>> vis(n,vector<int>(m,0));
	vector<vector<int>> thres(n,vector<int>(m,0));
	for(auto &i: indi)
		for(int &j: i)cin >> j;
	for(auto &i: thres)
		for(int &j: i)cin >> j;
	multiset<node> s;
	while(k--){
		int a,b;
		cin >> a >> b;
		a--,b--;
		dis[a][b] = 0;
		s.emplace(a,b,0);
	}
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	while(s.size()){
		int i = s.begin()->i, j = s.begin()->j;
		s.erase(s.begin());
		if(vis[i][j])continue;
		vis[i][j] = true;
		for(int k = 0; k < 4; ++k){
			int x = i + dx[k], y = j + dy[k];
			if(x < 0 || x >= n || y < 0 || y >= m)continue;
			if(dis[x][y] > dis[i][j] + indi[x][y]){
				int cost = dis[i][j] + indi[x][y];
				if(cost > thres[x][y])continue;
				dis[x][y] = cost;
				s.emplace(x,y,dis[x][y]);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)printf("%d ",thres[i][j] >= dis[i][j]);
		printf("\n");
	}
	return 0;
}

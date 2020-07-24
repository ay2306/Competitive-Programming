//https://codeforces.com/contest/515/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int n,m,deg[N][N],vis[N][N];
string a[N];
vector<pair<int,int>> g[N][N];

bool dfs(int i, int j, int pi = -1, int pj = -1){
	vis[i][j] = 1;
	for(auto& [x,y]: g[i][j]){
		if(make_pair(x,y) == make_pair(pi,pj))continue;
		if(vis[x][y] == 1)return false;
		if(!vis[x][y] && !dfs(x,y,i,j))return false;
	}
	vis[i][j] = 2;
	return true;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)cin >> a[i];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] != '.')continue; 
			if(i+1 < n && a[i+1][j] == '.')g[i][j].emplace_back(i+1,j),g[i+1][j].emplace_back(i,j);
			if(j+1 < m && a[i][j+1] == '.')g[i][j].emplace_back(i,j+1),g[i][j+1].emplace_back(i,j);	
		}
	}

	queue<pair<int,int>> q;
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			deg[i][j] = g[i][j].size();
			if(g[i][j].size() == 1)q.emplace(i,j);
		}
	}
	while(q.size()){
		int i,j;
		tie(i,j) = q.front();
		q.pop();
		if(vis[i][j])continue;
		vis[i][j] = 1;
		deg[i][j]--;
		for(auto& [x,y]: g[i][j]){
			if(vis[x][y])continue;
			for(auto& [ox,oy]: g[x][y]){
				deg[ox][oy]--;
				if(deg[ox][oy] == 1 && !vis[ox][oy]){
					q.emplace(ox,oy);
				}
			}
			vis[x][y] = 1;
			if(y == j && x+1 == i)a[i][j] = 'v', a[x][y] = '^';
			if(y == j && x == i+1)a[i][j] = '^', a[x][y] = 'v';
			if(y == j+1 && x == i)a[i][j] = '<', a[x][y] = '>';
			if(y+1 == j && x == i)a[i][j] = '>', a[x][y] = '<';
			break;
		}
	}
	for(int i = 0; i < n; ++i)	
		for(int j = 0; j < m; ++j)
			if(a[i][j] == '.')return cout << "Not unique" , 0;
	for(int i = 0; i < n; ++i)cout << a[i] << "\n";
	return 0;
}
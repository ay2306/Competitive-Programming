#include<bits/stdc++.h>
using namespace std;
string a[1010];
pair<int,int> parent[1010][1010];
int n,m,vis[1010][1010],sx,sy,tx,ty,x,y,i,j;
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
bool valid(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#';
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i)cin >> a[i];	
	for(int i = 0 ; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(a[i][j] == 'A')sx=i,sy=j;
			else if(a[i][j] == 'B')tx=i,ty=j;
	queue<pair<int,int>> q;
	q.emplace(sx,sy);
	vis[sx][sy] = 1;
	parent[sx][sy] = make_pair(-1,-1);
	while(q.size()){
		tie(i,j) = q.front();
		q.pop();
		for(int k = 0; k < 4; ++k){
			x = i + dx[k], y = j + dy[k];
			if(!valid(x,y))continue;
			if(vis[x][y]) continue;
			q.emplace(x,y);
			parent[x][y] = make_pair(i,j);
			vis[x][y] = 1;
		}
	}
	if(!vis[tx][ty])return cout << "NO",0;
	string ans = "";
	while(true){
		tie(i,j) = parent[tx][ty];
		if(i == -1)break;
		if(i == tx){
			if(j > ty)ans+="L";
			else ans+="R";
		}else{
			if(i > tx)ans+="U";
			else ans+="D";
		}
		tx = i, ty = j;
	}
	reverse(ans.begin(),ans.end());
	return cout << "YES\n" << ans.size() << "\n" << ans ,0;
}

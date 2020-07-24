#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
char s[1010][1010];
int n,m,x,y,i,j;
int lev1[1010][1010],lev2[1010][1010];
pair<int,int> parent[1010][1010];
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
string aux = "UDRL";
bool valid(int i, int j){
	return i > 0 && i <= n && j > 0 && j <= m && s[i][j] != '#';
}
template<typename T>
void bfs(queue<pair<int,int>> &q, T lev){
	while(q.size()){
		tie(i,j) = q.front();
		q.pop();
		for(int k = 0; k < 4; ++k){
			x = i + dx[k], y = j + dy[k];
			if(!valid(x,y))continue;
			if(~lev[x][y])continue;
			lev[x][y] = lev[i][j] + 1;
			q.emplace(x,y);
			parent[x][y] = pair<int,int> (i,j);
		}
	}
}

void printPath(int x, int y){
	string ans = "";
	while(~parent[x][y].first){
		tie(i,j) = parent[x][y];
		for(int dir = 0; dir < 4; ++dir){
			if(x != i+dx[dir] || y != j+dy[dir])continue;
			ans+=aux[dir];
			break;
		}
		tie(x,y) = parent[x][y];
	}
	reverse(ans.begin(),ans.end());
	printf("YES\n%d\n",ans.size());
	for(auto i: ans)printf("%c",i);
}

int main(){
	memset(lev1,-1,sizeof(lev1));
	memset(lev2,-1,sizeof(lev2));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i)scanf("%s",s[i]+1);
	vector<pair<int,int>> exitPos,monsterPos;
	pair<int,int> a;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(s[i][j] == 'M')monsterPos.emplace_back(i,j);
			else if(s[i][j] == 'A')a = pair<int,int> (i,j);
			if(s[i][j] != '#' && (i == 1 || i == n || j == 1 || j == m))exitPos.emplace_back(i,j);
		}
	}
	queue<pair<int,int>> q;
	for(auto& [x,y]: monsterPos)q.emplace(x,y),lev1[x][y] = 0;
	bfs(q,lev1);	
	q.emplace(a);
	lev2[a.first][a.second] = 0;
	parent[a.first][a.second] = pair<int,int> (-1,-1);
	bfs(q,lev2);
	for(auto& [x,y]:exitPos){
		if(lev2[x][y] < lev1[x][y] || (lev1[x][y] == -1 && lev2[x][y] != -1)){
			printPath(x,y);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

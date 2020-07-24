#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,r;
	cin >> n >> m >> k;
	r = (n > m);
	vector<vector<char>> row,col;
	for(int i = 0; i < 2*n-1; ++i){
		string a;
		cin >> a;
		if(i&1^1)row.emplace_back(vector<char> (a.begin(),a.end()));
		else col.emplace_back(vector<char> (a.begin(),a.end()));
	}
	int e = 0,ne = 0;
	if(k == 1){
		for(auto&i: row)for(char &j:i)e+=j=='E',ne+=j!='E';
		for(auto&i: col)for(char &j:i)e+=j=='E',ne+=j!='E';
		if(e >= 3*ne){
			cout << "YES\n";
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j)cout << 1 << " ";
				cout << "\n";	
			}
			return 0;
		}else return cout << "NO\n",0;
	}
	if(r){
		vector<vector<char>> a(m-1),b(m);
		for(int i = 0; i < m-1; ++i){
			for(int j = 0; j < n; ++j)a[i].emplace_back(row[j][i]);
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n-1; ++j)b[i].emplace_back(col[j][i]);
		}
		row = b;
		col = a;
		swap(n,m);
	}
	cout << "YES\n";
	vector<vector<int>> ans(n,vector<int> (m,1));
	for(int i = 0; i < n; ++i){
		for(int j = 1; j < m; ++j){
			if(row[i][j-1]=='E')ans[i][j] = ans[i][j-1];
			else ans[i][j] = 3 - ans[i][j-1];
		}
		if(!i)continue;
		int okay = 0, bad = 0;
		for(int j = 0; j < m; ++j){
			if(col[i-1][j] == 'E')okay+=ans[i][j]==ans[i-1][j],bad+=ans[i][j]!=ans[i-1][j];
			else okay+=ans[i][j]!=ans[i-1][j],bad+=ans[i][j]==ans[i-1][j];
		}
		if(bad > okay){
			for(int j = 0; j < m; ++j)ans[i][j] = 3 - ans[i][j];
		}
	}
	if(r){
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j)cout << ans[j][i] << " ";
			cout << "\n";
		}
		return 0;
	}else{
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}

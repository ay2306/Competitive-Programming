#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,ans=INT_MAX,cost=0;;
	cin >> n >> m;
	string a;
	cin >> a;
	vector<int> pos;
	for(int i = 0; i < n; ++i)pos.emplace_back(i);
	string res = "";
	for(char i = '0'; i <= '9'; ++i){
		string cur = a;
		cost = 0;
		sort(pos.begin(),pos.end(),[i,a](const int &x,const int &y)->bool{
			if(abs(a[x]-i) != abs(a[y]-i))return abs(a[x]-i) < abs(a[y]-i);
			if(a[x] == a[y] && a[x] < i)return x>y;
			if(a[x] == a[y] && a[x] >= i)return x<y;
			if(a[x] != a[y] && a[x] >= i)return true;
			if(a[x] != a[y] && a[x] < i)return false;
		});
		for(int j = 0; j < m; ++j){
			cost += abs(a[pos[j]]-i);
			cur[pos[j]] = i;
		}
		if(cost < ans)ans = cost,res = cur;
		else if (cost == ans)res = min(res,cur);
	}
	return cout << ans << "\n" << res,0;
}
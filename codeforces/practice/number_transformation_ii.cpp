//https://codeforces.com/contest/346/problem/C
#include<bits/stdc++.h>
using namespace std;

vector<int> x,x1;

int main(){
	int n,a,b,ans=0;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&a);
		x.emplace_back(a);
	}
	sort(x.begin(),x.end());
	x.resize(unique(x.begin(),x.end())-x.begin());
	scanf("%d%d",&a,&b);
	while(a != b){
		x1.clear();
		int next_move = a - 1;
		for(auto &i: x){
			int p = a / i * i;
			if(p >= b){
				next_move = min(next_move, p);
				x1.emplace_back(i);
			}
		} 
		a = next_move;
		x = x1;
		ans++;
	}
	return cout << ans << "\n",0;
}

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> optimalUtilization(int mx, vector<pair<int,int>> f, vector<pair<int,int>> r){
	vector<pair<int,int>> ans;
	for(auto &i: f)swap(i.first,i.second);
	for(auto &i: r)swap(i.first,i.second);
	sort(f.begin(),f.end());
	sort(r.begin(),r.end());
	int Max = 0;
	for(auto i: f){
		if(mx < i.first)continue;
		int index = upper_bound(r.begin(),r.end(),make_pair(mx-i.first,INT_MAX)) - r.begin();
		if(index == 0)continue;
		index--;
		Max = max(i.first+r[index].first,Max);
	}
	for(auto i: f){
		if(Max < i.first)continue;
		vector<pair<int,int>>::iterator it1,it2;
		it1 = lower_bound(r.begin(),r.end(),make_pair(Max-i.first,INT_MIN));
		it2 = upper_bound(r.begin(),r.end(),make_pair(Max-i.first,INT_MAX));
		while(it1 != it2){
			ans.emplace_back(i.second,it1->second);
			it1++;
		}
	}
	return ans;
}

int main(){
	int n,m,mx;
	cin >> n >> m >> mx;
	vector<pair<int,int>> a(n),b(m);
	for(auto &i: a)cin >> i.first >> i.second;
	for(auto &i: b)cin >> i.first >> i.second;
	auto res = optimalUtilization(mx,a,b);
	for(auto i: res)cout << i.first << " " << i.second << "\n";
	return 0;
}
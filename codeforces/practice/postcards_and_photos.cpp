#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	cin >> a;
	vector<pair<char,int>> c;
	for(char i: a){
		if(c.size() && c.back().first == i)c.back().second++;
		else c.emplace_back(i,1);
	}
	int ans = 0;
	for(auto i: c)ans += (i.second + 4)/5;
	return cout << ans , 0 ;
}

//https://codeforces.com/contest/135/problem/C
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin >> a;
	set<string> ans;
	int o = 0, z = 0, sp = 0;
	int one_del = a.size() - 1 >> 1;
	int zero_del = a.size() - 2 >> 1;
	for(char i: a){
		o += i == '1';
		z += i == '0';
		sp += i == '?';
	}
	if(o+sp > one_del+1)ans.emplace("11");
	if(z+sp > zero_del+1)ans.emplace("00");
	if(a.back() == '?'){
		sp--;
		o++;
		int o_req = one_del + 1 - o;
		int z_req = zero_del + 1 - z;
		if(o_req >= 0 && z_req >= 0 && o_req + z_req == sp)ans.emplace("01");
		o--;
		z++;
		o_req = one_del + 1 - o;
		z_req = zero_del + 1 - z;
		if(o_req >= 0 && z_req >= 0 && o_req + z_req == sp)ans.emplace("10");
	}
	if(a.back() == '1'){
		int o_req = one_del + 1 - o;
		int z_req = zero_del + 1 - z;
		if(o_req >= 0 && z_req >= 0 && o_req + z_req == sp)ans.emplace("01");
	}
	if(a.back() == '0'){
		int o_req = one_del + 1 - o;
		int z_req = zero_del + 1 - z;
		if(o_req >= 0 && z_req >= 0 && o_req + z_req == sp)ans.emplace("10");
	}
	for(auto i: ans)cout << i << "\n";
	return 0;
}

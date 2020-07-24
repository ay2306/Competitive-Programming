#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[20][2], power[17];
string s;

int numerate(int pos){
	int num = 0;
	for(int i = pos + 1; i < s.size(); ++i){
		num *= 10;
		num += s[i] - '0';
	}
	return num + 1;
}

int sum(int pos, bool tight){
	if(pos >= s.size())return 0;
	int &res = dp[pos][tight];
	if(~res)return res;
	int lim = s[pos] - '0';
	if(!tight)lim = 9;
	res = 0;
	for(int i = 0; i <= lim ; ++i){
		if(i == lim && tight)res += i * numerate(pos) + sum(pos + 1, true);
		else res += i * power[s.size() - pos - 1] + sum(pos + 1, false); 
	}
	return res;
}

signed main(){
	power[0] = 1;
	for(short i = 1; i < 17; ++i)power[i] = 10LL*power[i-1];
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		l--;
		memset(dp,-1,sizeof(dp));
		s = to_string(r);
		int s1 = sum(0,true);
		memset(dp,-1,sizeof(dp));
		s = to_string(l);
		int s2 = 0;
		if(l > 0)s2 = sum(0,true);
		cout << s1 - s2 << "\n";
	}
	return 0;
}
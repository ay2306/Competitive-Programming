#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int cnt = 0, ans = 0;
	char cur = '-';
	for(char i: s){
		if(i == cur)cnt++;
		else cnt = 1;
		ans = max(ans,cnt);
		cur = i;
	}
	cout << ans;
	return 0;
}

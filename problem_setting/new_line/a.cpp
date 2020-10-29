#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	string s, a = "";
	getline(cin,s);
	for(int i = 0; i <= s.size(); ++i){
		if(i == s.size() || s[i] == ' '){
			cout << a << "\n";
			a = "";
		}else a+=s[i];
	}
	return 0;
}

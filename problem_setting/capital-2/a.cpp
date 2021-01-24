#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	string s;
	getline(cin,s);
	int cap = 0, small = 0;
	for(char i: s){
		cap+=(i >= 'A' && i <= 'Z');
		small+=(i >= 'a' && i <= 'z');
	}
	cout << cap << " " << small << "\n";
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	set<int> s;
	const int N = 1e6+1;
	for(int i = 1; i <= N; ++i)s.emplace(i*i);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(s.count(x))cout << "Ayush\n";
		else cout << "Harsh\n";
	}
	return 0;
}

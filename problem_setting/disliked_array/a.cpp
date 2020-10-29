#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a,n,nn = 0, ng = 0;
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> a;
			nn+=(a >= 0);
			ng+=(a <= 0);
		}
		if(nn == n || ng == n)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

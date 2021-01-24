#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q,l,r;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> d1(n+1,0),d2(n+1,0);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	while(q--){
		cin >> l >> r;
		l--,r--;
		int len = r-l+1;
		if(len & 1){
			int mid = l + r >> 1;
			if(r-mid+1 <= d1[mid])cout << "yes\n";
			else cout << "no\n";
		}else{
			int index = r - len/2 + 1;
			if(d2[index] >= len/2)cout << "yes\n";
			else cout << "no\n";
		}
	}	
	return 0;
}

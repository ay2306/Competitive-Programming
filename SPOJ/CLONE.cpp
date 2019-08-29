#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

int main() {
	FAST
	while(1){
		int a,b;
		cin >> a >> b;
		if(a == 0)break;
		unordered_map<string,int> m;
		for(int i = 0; i < a; ++i){
			string p;
			cin >> p;
			m[p]++;
		}
        vector<int> ans(a,0);
        for(auto &i: m){
            ans[i.second-1]++;
        }
        for(int i = 0; i < a; ++i){
            cout << ans[i] << "\n";
        }
	}
	return 0;
}
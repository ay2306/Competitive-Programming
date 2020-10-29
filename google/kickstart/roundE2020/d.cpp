#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    set<string> w,ans;
	    int n;
	    cin >> n;
	    string s,cur = "";
	    for(int i = 0; i < n; ++i){
	        cin >> s;
	        w.emplace(s);
	    }
	    cin >> s;
	    function<void(int,string)> solve = [&](int i, string a)->void{
			if(i == s.size()){
				return void(ans.emplace(a));
			}
			string here = "";
	        for(int j = i; j < s.size(); ++j){
	            if(i == j && a.size())a+=" ";
	            here+=s[j];
	            a+=s[j];
	            if(w.count(here))solve(j+1,a);
	        }
	    };
	    solve(0,"");
	    for(auto i: ans)cout << "("<<i<<")";
	    cout << "\n";
	}
	return 0;
}
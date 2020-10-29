#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
	int t = 0;
	while(1){
		int n;
		if(cin >> n){}
		else break;
		if(t)cout << "\n";
		t++;
		ord_set<pair<int,int>> s;
		int cnt = 0;
		while(1){
			if(~n)s.insert(pair<int,int> (n,++cnt));
			else if(cnt & 1){
				cout << s.find_by_order(cnt/2)->first << "\n";
			}else{
				cout << s.find_by_order(cnt/2-1)->first << "\n";
			}
			cin >> n;
			if(n == 0)break;
		}
	}
	return 0;
}

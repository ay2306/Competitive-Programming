#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<ll> vec[10000];
		int n;
		cin >> n;
		int dist = 0;
		int a;
		for(int i = 0; i < n; ++i){
			cin >> a;
			ll k = a%10000;
			if(vec[k].size()==0){
				dist++;
				vec[k].push_back(a);
			}else{
				bool found = false;
				for(vector<ll>::iterator itr = vec[k].begin(); itr != vec[k].end(); ++itr){
					if(*itr == a){
						found = true;
						break;
					}
				}
				if(!found){
					dist++;
					vec[k].push_back(a);
				}
			}
		}
		ll m = dist*(dist-1);
		m/=2;
		if(n==1)cout << "1\n";
		if(n!=1)cout << m << endl;
	}
	return 0;
}

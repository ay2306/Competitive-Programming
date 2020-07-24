#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long int ans = 1;
	vector<int> arr(n),a;
	for(int &i: arr)cin>>i;
	for(int i = 0; i < n; ++i){
		if(arr[i])continue;
		if(a.size() && arr[i-1] == arr[i])a.back()++;
		else a.emplace_back(1);
	}
	if(accumulate(arr.begin(),arr.end(),0) == 0)return cout << 0 << "\n", 0;
	if(arr[0] == 0)a.erase(a.begin());
	if(a.size() && arr.back()==0)a.pop_back();
	for(int i: a)ans = ans * 1LL * (i+1);
	return cout << ans << "\n",0;
}

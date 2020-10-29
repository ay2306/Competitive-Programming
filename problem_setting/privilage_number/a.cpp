#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
int p[N];

int main(){
	for(int i = 2; i < N; ++i){
		if(p[i])continue;
		for(int j = i; j < N; j+=i)p[j] = i;
	}
	int n,mx = 0;
	scanf("%d",&n);
	function<int(int)> getFactorCnt = [&](int x)->int{
		int ans = 1;
		while(x > 1){
			int prime = p[x],cnt = 1;
			while(x % prime == 0)cnt++, x/=prime;
			ans*=cnt;
		}
		return ans;
	};
	vector<int> arr(n);
	for(int &i: arr)scanf("%d",&i);
	for(int i: arr)mx = max(mx,getFactorCnt(i));
	int ans = 0;
	for(int i: arr)ans+=getFactorCnt(i) != mx;
	printf("%d",ans);
	return 0;
}

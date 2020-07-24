#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int n,ans,arr[N],dp[N];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
	unordered_map<int,int> m(1 << 12);
	for(int i = 1; i <= n; ++i){
		if(!m.count(arr[i]))m[arr[i]]= -1;
		dp[i] = max(ans,min(dp[i-1]+1,i-m[arr[i]]));
		m[arr[i]] = i;
	}	
	return printf("%d",*max_element(dp+1,dp+n+1)),0;
}

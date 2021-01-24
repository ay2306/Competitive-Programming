#include<bits/stdc++.h>
using namespace std;

long long getAns(int k){
	switch(k){
		case 1: return 0;
		case 2: return 6;
		case 3: return 28;
		case 4: return 96;
		case 5: return 252;
		case 6: return 550;
		case 7: return 1056;
		case 8: return 1848;
	}
	long long ans = 0;
	// Innermost layer
	{
		long long cells = (k-2)*1LL*(k-2);
		ans += cells*8;
	}
	// Middle Layer
	{
		long long cells = 4*k-4;
		long long edges = 4;
		ans += edges * 4;
		ans += (cells-edges)*6;
	}
	// Outer Layer
	{
		long long cells = 4*k;
		long long edges = 4;
		long long along_edge = 8;
		ans += edges * 2;
		ans += along_edge * 3;
		ans += (cells - edges - along_edge) * 4;
	}
	long long cells = k*k;
	long long ways = cells * (cells - 1) / 2;
	return ways - ans / 2; // Recounting
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)printf("%lld\n",getAns(i));
	return 0;
}

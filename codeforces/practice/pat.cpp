#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int dp[1010] = {};
    for(int i = 0; i <= n; ++i){
    	bool win = false;
	if(i-1 >= 0)win = win || !dp[i-1];
	if(i-2 >= 0)win = win || !dp[i-2];
	if(i-k >= 0)win = win || !dp[i-k];
	dp[i] = win;
	dp[i] ? printf(" i = %d (win)\n",i) : printf(" i = %d (lose)\n",i);
    }
    return 0;
}

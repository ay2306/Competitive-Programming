#include<bits/stdc++.h>
using namespace std;

int solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n < k || k % 3 != 0)return n%3 == 0;
	int index = (n - k + 3) % (k+1);
	return (index == 0) || (index > 1 && (index - 1)%3 == 0);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve()?printf("Bob\n"):printf("Alice\n");
	return 0;
}

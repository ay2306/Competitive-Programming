#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(n%2 == 0)return printf("Marsel"),0;
	for(int i = 1; i * i <= m; ++i){
		if(m % i) continue;
		if((i >= k && i != m) || (m/i >= k && i != 1))return printf("Timur"),0;
	}
	return printf("Marsel"),0;
}

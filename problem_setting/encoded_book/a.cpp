#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> m;
	int n,a,ans=-1;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&a);
		m[a]++;
		if(m[ans] < m[a])ans = a;
		else if(m[ans] == m[a])ans = max(ans,a);
		printf("%d\n",ans);
	}
	return 0;
}

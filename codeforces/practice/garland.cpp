#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

vector<int> g[N];
int a[N],s[N],sum=0,root,n,c,s1=-1,s2=-1;

int dfs(int u){
	s[u] = a[u];
	for(auto &i: g[u])s[u]+=dfs(i);
	if(s[u] == sum/3 && u != root && s1 == -1)s1=u,s[u]=0;
	else if(s[u] == sum/3 && u != root && s2 == -1)s2=u,s[u]=0;
	return s[u];
}

int main(){	
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d",&c,a+i);
		if(c)g[c].emplace_back(i);
		else root = i;
		s[i] = INT_MAX;
	}
	sum = accumulate(a+1,a+n+2,0);
	dfs(root);
	if(sum%3 == 0 && s1 != -1 && s2 !=-1)printf("%d %d",s1,s2);
	else printf("-1\n");
	return 0;
}
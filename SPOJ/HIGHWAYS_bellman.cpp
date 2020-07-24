#include<bits/stdc++.h>
using namespace std;
const int inf = 2e9	;
struct edge{
	int a,b,c;
	edge(int a, int b, int c):a(a),b(b),c(c){}
};

int n,t,m,s,d,c,a,b;
vector<edge> e;

int bellman(int s){
	vector<int> dis(n+1,inf);
	dis[s] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(dis[e[j].a] < inf){
				dis[e[j].b] = min(dis[e[j].b],dis[e[j].a]+e[j].c);
			}
		}
	}
	return dis[d];
}

int main(){
	scanf("%d",&t);
	while(t--){
		e.clear();
		scanf("%d%d%d%d",&n,&m,&s,&d);
		for(int i = 1; i <= m; ++i){
			scanf("%d%d%d",&a,&b,&c);
			e.emplace_back(a,b,c);
		}
		int res = bellman(s);
		if(res == inf)printf("NONE\n");
		else printf("%d\n",res);
	}	
	return 0;

}

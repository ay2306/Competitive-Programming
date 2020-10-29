#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int test = 1; test <= t; ++test){
		int n,a,b,c;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		if(a+b-c > n)printf("IMPOSSIBLE\n");
		else if(n == 1)printf("1\n");
		else{
			a-=c,b-=c;
			list<int> ans;
			int rem = n + c - a - b;
			if(c == 1 && a == 0 && b == 0 && rem != 0){
				printf("IMPOSSIBLE\n");
				continue;
			}
			if(c > 1){
				for(int i = 0; i < a; ++i)ans.emplace_back(n-1);
				ans.emplace_back(n);
				for(int i = 0; i < rem; ++i)ans.emplace_back(1);
				for(int i = 1; i < c; ++i)ans.emplace_back(n);
				for(int i = 0; i < a; ++i)ans.emplace_back(n-1);
			}else{

			}
		}
	}
	return 0;
}
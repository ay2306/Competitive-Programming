#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,s1=0,s2=0;
	for(int i = 0; i < 3; ++i){cin >> a; s1+=a;}
	for(int i = 0; i < 3; ++i){cin >> a; s2+=a;}
	cin >> n;
	(s1+4)/5 + (s2+9)/10 <= n ? printf("YES") : printf("NO");
	return 0;
}

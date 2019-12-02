#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("output1.txt","w",stdout);
	string oper = "*+-";
	int c = 0;
	for(int i = 350; i < 475; ++i){
		cout << i << " " << oper[c%3] << " " << i+1 << "\t";
		int ans;
		if(c%3 == 1){
			ans = i+i+1;
		}else if(c%3 == 2)ans = (i - (i+1));
		else ans = i*(i+1);
		c++;
		cout << ans << "\t" << ans+1 << "\t" << ans+2 << "\n";
	}
return 0;
}

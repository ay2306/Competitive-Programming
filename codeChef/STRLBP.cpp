#include<iostream>
using namespace std;

int main(){
	char s[10];
	int t;
	cin >> t;
	while(t--){
		int c = 0;
		cin >> s;
		for(int i = 0; i < 7; ++i){
			if(s[i]=='1'){
                if(s[i+1]=='0')c++;
			}else if(s[i]=='0'){
                if(s[i+1]=='1')c++;
			}
			if(c>2)break;
		}
		if(c>2)cout << "non-uniform\n";
		else{cout << "uniform\n";}
	}

return 0;
}

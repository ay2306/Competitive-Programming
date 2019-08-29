#include<bits/stdc++.h>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int k = 0;
		int a;
		for(int i = 0; i < 5; ++i){
			cin >> a;
			if(a==1)k++;
		}
		switch(k){
			case 0: cout << "Beginner\n";break;
			case 1: cout << "Junior Developer\n";break;
			case 2: cout << "Middle Developer\n";break;
			case 3: cout << "Senior Developer\n";break;
			case 4: cout << "Hacker\n";break;
			case 5: cout << "Jeff Dean\n";break;
		}
	}
return 0;
}



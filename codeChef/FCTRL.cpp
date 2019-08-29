#include <iostream>
#define ll long long int
using namespace std;
int main(){
	int t;
	ll a;
	ll b = 5;
	ll c = 0;
	cin >> t;
	for(int i = 0; i < t; ++i){
	    c = 0;
	    b = 5;
	    cin >> a;
	    while(a>b){
	        c+=(a/b);
	        b*=5;
	    }
	
	if(i>0)cout << endl;
	cout << c;
	    
	}
return 0;
}	

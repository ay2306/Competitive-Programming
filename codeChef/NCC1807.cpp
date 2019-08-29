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
		int n,k;
		cin >> n >> k;
		k = (n-1)*k;
		n*=(n+1);
		n/=2;
		n+=k;
		cout << n << endl;
	}
return 0;
}



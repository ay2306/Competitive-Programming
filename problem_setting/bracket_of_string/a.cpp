#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long int x;
		cin >> x;
		cout << (x%2 ? "no\n" : "yes\n");
	}
	return 0;
}

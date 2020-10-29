#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,n,a;
	cin >> x >> n;
	while(n--){
		cin >> a;
		cout << (a > x ? "outside" : "inside") << "\n";
	}
	return 0;
}

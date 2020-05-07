#include<bits/stdc++.h>
using namespace std;


int main(){
	long long int n;
	cin >> n;
	long long sum = n*(n+1)/2;
	// for(int i = 1; i <= n; ++i)sum+=i;
	cout << sum << '\n';
	return 0;
}
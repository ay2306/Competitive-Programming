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
		int n,k,b;
		cin >> n >> k >> b;
		int longest = 0; 
		int p = 0;
		int *arr = new int[n];
		for(int i = 0; i < n; ++i)cin >> arr[i];
		for(int i = 0; i+1 <n; ++i){
			if(arr[i+1]>=((k*arr[i])+b)){
				p++;
			}
		}
		cout << p << endl;
	}
return 0;
}



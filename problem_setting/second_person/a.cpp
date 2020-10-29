#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int &i: arr)scanf("%d",&i);
	sort(arr.rbegin(),arr.rend());
	printf("%d",arr[1]);
	return 0;
}

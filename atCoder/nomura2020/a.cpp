#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> &B){
	long long s[4] = {};
	for(int i: A)s[0]+=i;
	for(int i: B)s[1]+=i;
	int ans = 0;
	for(int i = 0; i+1 < A.size(); ++i){
		s[0]-=A[i];
		s[1]-=B[i];
		s[2]+=A[i];
		s[3]+=B[i];
		if(s[0] == s[1] && s[2] == s[3] && s[0] == s[3])
			ans++;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int &i : a)cin >> i;
	for(int &i : b)cin >> i;
	cout << solution(a,b);
	return 0;
}
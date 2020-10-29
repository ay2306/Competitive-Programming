#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B){
	int a = 0, b = 0;
	for(int i : A)a+=i;
	for(int i : B)b+=i;
	if(a < b)swap(A,B),swap(a,b);
	multiset<int> m;
	for
}

int main(){
	return 0;
}
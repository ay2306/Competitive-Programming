#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	if((s.length()%2==0)^(s[0] == s.back()))return printf("Second"),0;
	return printf("First"),0;
}

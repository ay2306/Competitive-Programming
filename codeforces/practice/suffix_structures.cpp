#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	map<char,int> m1,m2;
        for(char i: a)m1[i]++;
	for(char i: b)m2[i]++;
	for(auto i: m2)if(m1[i.first] < i.second)return printf("need tree"),0;
	for(int i = 0, j = 0; i < a.size(); ++i){
		j += a[i] == b[j];
		if(j == b.size())return printf("automaton"),0;
	}
	a.size() == b.size() ? printf("array") : printf("both");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
pair<string,string> convert(string &a){
	string a1 = "",a2 = "";
	int i = 0;
	while(a[i] != '-')a1+=a[i++];
	i++;
	while(i < a.size())a2+=a[i++];
	return {a1,a2};
}
vector<int> p;
int f(int x){
	if(p[x] < 0)return x;
	p[x] = f(p[x]);
	return p[x];
}

void un(int a, int b){
	a = f(a);
	b = f(b);
	if(a == b)return;
	if(p[a] < p[b])swap(a,b);
	p[b]+=p[a];
	p[a] = b;

}

int getResult(vector<string> relation){
	map<string,int> m;
	int c = 0;
	for(auto &i: relation){
		auto j = convert(i);
		if(m.count(j.first) == 0)m[j.first]=++c;
		if(m.count(j.second) == 0)m[j.second]=++c;
	}
	p = vector<int> (c+10,-1);
	for(auto &i: relation){
		auto j = convert(i);
		un(m[j.first],m[j.second]);
	}
	int ans = 0;
	for(auto &i: m){
		ans = max(ans,-p[f(i.second)]);
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	cout << getResult(a) << "\n";
	return 0;
}
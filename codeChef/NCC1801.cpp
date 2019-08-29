#include<bits/stdc++.h>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;

struct dataType{
	string a;
	int cnt;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		dataType p;
		vector<string> vec;
		vector<dataType> dvec;
		cin >> n;
		string a;
		getline(cin,a);
		stringstream obj(a);
		string tmp,out;
		obj >> tmp;
		vec.push_back(a);
		p.string = a;
		p.cnt = 0;
		dvec.push(p);
		while(true){
			obj >> out;
			if(out == tmp){
				break;
			}else{
				
			}
		}
	}
return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define PLL pair<long long, long long>
const ll inf = 1e9;

long long int parseNumber(string &a, int &i){
    ll num = 0;
    while(isdigit(a[i])){
        num = num*10%inf;
        num = (num + a[i]-'0')%inf;
    	i++;
    }
    return num;
}

pair<ll,ll> parser(string &a, int &i){
    pair<ll,ll> change(0,0);
    ll j;
    while(i < a.size()){
        if(isdigit(a[i]))j = parseNumber(a,i);
        if(a[i] == '('){
            i++;
            auto k = parser(a,i);
            change.first = (change.first + j*k.first%inf)%inf;
            change.second = (change.second + j*k.second%inf)%inf;
		}
        else if(a[i] == ')'){
            i++;
            return change;
        }
        else{
			if(a[i] == 'N')
				change.second = (change.second-1+inf)%inf;
			if(a[i] == 'S')
				change.second = (change.second+1)%inf;
			if(a[i] == 'E')
				change.first = (change.first+1)%inf;
			if(a[i] == 'W')
				change.first = (change.first-1+inf)%inf;
			i++;
		} 
	}
	return change;
}

void solve(int test_case){
	cout << "Case #" << test_case << ": ";
	string a;
	cin>> a;
	int i = 0;
	auto k = parser(a,i);
	k.first+=1;
	k.second+=1;
	cout << k.first << " " << k.second << "\n";
}

int main(){
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; ++i)solve(i);
	return 0;
}

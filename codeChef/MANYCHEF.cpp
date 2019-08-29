#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

bool check(string str,int i){
	if(str[i] != 'C' && str[i]  != '?') return false;
	if(str[i+1] != 'H' && str[i+1]  != '?') return false;
	if(str[i+2] != 'E' && str[i+2]  != '?') return false;
	if(str[i+3] != 'F' && str[i+3]  != '?') return false;
	return true;
}

void solve(){
	int tc;
	cin>>tc;
	string str;
	while(tc--){
		cin>>str;
		for(int i=str.size()-4;i>=0;i--){
			if(check(str,i)){
				str[i] = 'C';
				str[i+1] = 'H';
				str[i+2] = 'E';
				str[i+3] = 'F';
			}
		}
		for(int i=0;i<str.size();i++){
			if(str[i] == '?') str[i] = 'A';
		}
		cout<<str<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
  cin.tie(0);
		solve();
}

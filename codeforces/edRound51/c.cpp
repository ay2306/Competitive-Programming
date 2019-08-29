/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
 
}
int main(){
	FAST
	ll n;
	cin >> n;
	ll *arr = new ll[n];
	unordered_map<int,int> m;
	unordered_map<int,int> s;
	unordered_map<int,V<int> > ind;
	V<int> A[2];
	int ca = 0,cb=0;
	string ans = "";
	for(int i = 0; i < n; ++i){
		ans+="A";
		cin>> arr[i];
		if(m[arr[i]] == 0){
			V<int> v;
			v.pb(i);
			ind[arr[i]] = v;
		}else{
			ind[arr[i]].pb(i);
		}
		m[arr[i]]++;
		
	}
	// sort(arr,arr+n);
	for(auto s: ind){
		if(ca == cb){
			A[0].pb(s.second[0]);
			for(int i = 1; i < s.second.size(); ++i)A[1].pb(s.second[i]);
			if(m[s.first]!=2)ca++;
		}else{
			A[1].pb(s.second[0]);
			for(int i = 1; i < s.second.size(); ++i)A[0].pb(s.second[i]);
			if(m[s.first]!=2)cb++;
		}
	}
	for(int i = 0; i < A[1].size(); ++i){
		ans[A[1][i]]='B';
	}
	if(ca > cb){
		int i;
		int flag = 1;
		for(i = 0; i < n; ++i){
			if(ans[i] == 'A'){
				if(m[arr[i]] > 2){
					ans[i]='B';
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	cout << ans;
    return 0;
}
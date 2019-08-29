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
	unordered_map<ll,int> m;
	unordered_map<ll,int> m1;
	int n;
	int kind = 1;
	cin >> n;
	priority_queue<ll,V<ll>, greater<ll> > sell;
	priority_queue<ll,V<ll> > buy;
	for(int i = 0; i < n; ++i){
		string a;
		cin >> a;
		ll b = readInt();
		m[b] = 0;
		m1[b] = 0;
		if(a.length() == 3){
			if(sell.size() == 0){m[b]++;sell.push(b);}
			else{
				if(sell.top() > b){m[b]++;sell.push(b);}
			}
			if(buy.size() == 0){m[b]++;buy.push(b);}
			else{
				if(buy.top() < b){m[b]++;buy.push(b);}
			}
		}else{
			
		}
		// cout << buy.size() << " " << sell.size() << "\n";
	}
	if(!kind)return 0;
	ll ans = 1;
	for(auto it: m){
		// cout << it.second << " ";
		ans = (ans*(it.second))%MOD;
	}
	cout << ans;
    return 0;
}
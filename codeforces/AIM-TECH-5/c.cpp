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

int main(){
	FAST
	int n;
	cin >> n;
	PLL p[20];
	PLL *x = new PLL[n];
	PLL *y = new PLL[n];
	for(int i = 0; i < n; ++i){
		cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second; 
	}
	int ax = 1;
	if(ax == 1){
		ll l = LLONG_MIN, l1 = LLONG_MIN, r = LLONG_MAX, r1 = LLONG_MAX;
		for(int i = 0; i < n; ++i){
			if(x[i].first > l){
				l1 = l;
				l = x[i].first;
			}
			else if(x[i].first > l1){
				l1 = x[i].first;
			}
			if(x[i].second < r){
				r1 = r;
				r = x[i].second;
			}
			else if(x[i].second < r1){
				r1 = x[i].second;
			}
		}
		bool match = false;
		loop(i,0,n){
			if(x[i].first == l && x[i].second == r){
				match = true;
				break;
			}
		}
		p[0].first = l;
		p[1].first = l;
		p[2].first = l;
		p[3].first = l;
		p[4].first = l1;
		p[5].first = l1;
		p[6].first = l1;
		p[7].first = l1;
		p[8].first = r;
		p[9].first = r;
		p[10].first = r;
		p[11].first = r;
		p[12].first = r1;
		p[13].first = r1;
		p[14].first = r1;
		p[15].first = r1;
		
	}
	if(ax == 1){
		ll l = LLONG_MIN, l1 = LLONG_MIN, r = LLONG_MAX, r1 = LLONG_MAX;
		for(int i = 0; i < n; ++i){
			if(y[i].first > l){
				l1 = l;
				l = y[i].first;
			}
			else if(y[i].first > l1){
				l1 = y[i].first;
			}
			if(y[i].second < r){
				r1 = r;
				r = y[i].second;
			}
			else if(y[i].second < r1){
				r1 = y[i].second;
			}
		}
		bool match = false;
		loop(i,0,n){
			if(y[i].first == l && y[i].second == r){
				match = true;
				break;
			}
		}
		ll zero = 0;
		p[0].second = l;
		p[1].second = l1;
		p[2].second = r;
		p[3].second = r1;
		p[4].second = l;
		p[5].second = l1;
		p[6].second = r;
		p[7].second = r1;
		p[8].second = l;
		p[9].second = l1;
		p[10].second = r;
		p[11].second = r1;
		p[12].second = l;
		p[13].second = l1;
		p[14].second = r;
		p[15].second = r1;
		// if(match){
		// 	// cout << max(zero,r1-l1);
		// 	cout << r1;
		// }else{
		// 	// cout << max(max(zero,r1-l),max(zero,r-l1));
		// 	if(r1-l > r-l1){
		// 		cout << r1;
		// 	}else{
		// 		cout << r;
		// 	}
		// }
	}
	for(int j = 0; j < 16; ++j){
		int cnt = 0;
		// cout << p[j].first << " " << p[j].second << " ";
		for(int i = 0; i < n; ++i){
			if((p[j].first>=x[i].first && p[j].first<=x[i].second)&&(p[j].second>=y[i].first && p[j].second<=y[i].second))cnt++;
		}
		// cout << cnt << endl;
		if(cnt >= n-1){
			cout << p[j].first << " " << p[j].second;
			return 0;
		}
	}
   return 0;
}
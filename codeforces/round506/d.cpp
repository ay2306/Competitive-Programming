/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
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
    // FILE_READ
    FAST
    map<ll,ll> m[15];
    int n;
    ll k;
    // cin >> n >> k;
    // scanf("%d %lld",&n,&k);
    n = readInt();
    k = readInt();
    ll ans = 0;
    ll *arr = new ll[n];
    for(int i = 0; i < n; ++i){
        ll a;
        // cin >> arr[i];
        // scanf("%lld",&arr[i]);
        arr[i] = readInt();
        a = arr[i];
        int o = 1;
        for(ll j = 10; j < 100000000000; j*=10){
            a = (a*10)%k;
            m[o][a]++;
            o++;
        }
    }
    for(int i = 0; i < n; ++i){
        ll a;
        a = arr[i];
        ll tmp = a;
        int cnt = 0;
        while(tmp > 0){
            cnt++;
            tmp/=10;
        }
        ll p = a%k;
        if(p != 0)p = k - p;
        // ans+=(m[cnt][p]);
        auto it = m[cnt].find(p);
        if(it!=m[cnt].end())ans+=it->second;
        ll j = 1;
        for(int po = 0; po < cnt; ++po)j*=10;
        if(((a%k)*(j%k))%k == p)ans--;
    }
    cout << ans;
    return 0;
}
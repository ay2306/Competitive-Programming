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
ll n,c1,c2,mn;
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
unordered_map<pair<ll,ll>, ll> m;
ll next_move(ll cur, ll sum, ll cost,ans){
    if(sum == n){
        if(cost < mn){
            ans = 1;
            mn = cost;
        }
        else if(cost == mn){
            ans++;
        }
        return ans;
    }
    if(cost > mn)return LLONG_MAX;
    if(sum > n)return;
    if(cur > n)return;
    if(cur!=0)return next_move(cur,sum+cur,cost+c2,ans);
    if(cur!=sum)return next_move(sum,sum,cost+c1,ans);
}

int main(){
    mn = LLONG_MAX;
    n = readInt();
    c1 = readInt();
    c2 = readInt();
    next_move(0,1,0);
    cout << mn << " " << ans;
    return 0;
}

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
#define pb emplace_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
using namespace std;
ll dp[1010][1010][3];
PLL d[1010];
void solve(int test_case){
	ll n,W,x,y;
	cin >> n >> W >> x >> y;
	if(x > y)swap(x,y);
	loop(i,1,n+1)cin >> d[i].S;
	loop(i,1,n+1)cin >> d[i].F;
	sort(d+1,d+n+1);
	ll ans = 0;
	loop(i,1,n+1){
		loop(j,1,W+1){
			loop(k,0,3)dp[i][j][k] = dp[i-1][j][k];
			if(d[i].S <= j){
				dp[i][j][0] = max({dp[i][j][0],dp[i-1][j-d[i].S][0]+d[i].F});
				dp[i][j][1] = max({dp[i][j][1],dp[i-1][j-d[i].S][0]+d[i].F*x,dp[i-1][j-d[i].S][1]+d[i].F});
				dp[i][j][2] = max({dp[i][j][2],dp[i-1][j-d[i].S][1]+d[i].F*y,dp[i-1][j-d[i].S][2]+d[i].F});
			}
			loop(k,0,3)ans = max(ans,dp[i][j][k]);
		}
	}
	cout << ans << "\n";
}

int main(){
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}

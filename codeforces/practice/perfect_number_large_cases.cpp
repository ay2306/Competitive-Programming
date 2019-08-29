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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e18;
V<int> num;
ll dp[20][2][11];

ll cal(int pos, int smaller, int sum){
    if(pos == num.size()){
        if(sum == 10)return 1;
        else return 0;
    }
    if(sum > 10)return 0;
    if(dp[pos][smaller][sum] != -1)return dp[pos][smaller][sum];
    int last;
    if(smaller)last = 9;
    else last = num[pos];
    ll res = 0;
    for(int i = 0; i <= last; ++i){
        if(i == last && !smaller)res+=cal(pos+1, 0, sum+i);
        else res+=cal(pos+1,1,sum+i);
    }
    dp[pos][smaller][sum] = res;
    return dp[pos][smaller][sum];
}

ll number(ll a){
    num = V<int> ();
    while(a){
        num.pb(a%10);
        a/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    return cal(0,0,0);
}

ll solve(ll k){
    ll high = maxn;
    ll low = 0;
    ll ans = LLONG_MAX;
    while(low <= high){
        ll mid = (low + high)/2;
        // cout << "Low =  " << low << " " << " High = "<< high << "Mid =  " << mid << endl;
        ll cont = number(mid);
        if(cont > k){
            high = mid-1;
        }else if(cont < k){
            low = mid+1;
        }else{
            ans = min(mid,ans);
            high = mid-1;
        }
        // cout << "Cont = " << cont << endl;
        // cout << ans << "\n";
    }
    while(number(ans-1) == k && ans > 0)ans--;
    return ans;
}

int main(){
    ll n;
    cin >> n;
    cout << solve(n);
}
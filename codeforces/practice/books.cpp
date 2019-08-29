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
vector<ll> arr;
ll n,t;

bool check(ll k){
    ll sum = 0;
    for(int i = 0; i < k; ++i){
        sum+=arr[i];
    }
    if(sum <= t)return true;
    for(int i = k; i < n; ++i){
        sum+=arr[i];
        sum-=arr[i-k];
        if(sum <= t)return true;
    }
    return false;
}

int main(){
    cin >> n >> t;
    arr = vector<ll> (n,0);
    loop(i,0,n)cin >> arr[i];
    ll low = 0;
    ll high = n;
    ll ans = low;
    while(low <= high){
        ll mid = (high+low)/2;
        if(check(mid)){
            ans = max(mid,ans);
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout << ans;
    return 0;
}
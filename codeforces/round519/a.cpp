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
    int n;
    cin >> n;
    ll s1 = 0;
    ll s2 = 0;
    ll mx = 0;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    loop(i,0,n)mx=max(arr[i],mx);
    loop(i,0,n)s1+=arr[i];
    ll high = 10000;
    ll low = mx;
    ll ans = high;
    while(low <= high){
        ll mid = (low+high)/2;
        s2 = 0;
        for(int i = 0; i < n; ++i){
            s2+=(mid-arr[i]);
        
        }
        if(s2 > s1){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}
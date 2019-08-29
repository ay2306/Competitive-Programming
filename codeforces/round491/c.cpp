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
ll n;

bool eaten(ll k){
    // cout << "k = " << k << endl;
    ll rem = n;
    ll a = 0;
    ll b = 0;
    while(rem > 0){
        if(rem >= k)a+=max(k,1LL*0);
        else a+=rem;
        rem-=k;
        b+=max((rem/10),1LL*0);
        rem -= (rem/10);
        // cout << "rem = " << rem << " a = " << a << " b = " << b << endl;
    }
    // cout << " a = " << a << " b = " << b << " \n";
    return a >= b;
}

int main(){
    cin >> n;
    ll low = 1;
    ll ans = LONG_LONG_MAX;
    ll high = n;
    while(low <= high){
        ll mid = (low+high)/2;
        if(eaten(mid)){
            high = mid-1;
            ans = min(ans,mid);
        }
        else low = mid+1;
    }
    cout << ans;
    return 0;
}
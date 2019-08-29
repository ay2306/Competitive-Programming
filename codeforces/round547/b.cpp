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

const ll maxn = 1e5;

int main(){
    V<PLL> arr;
    int n;
    cin >> n;
    ll a;
    cin >> a;
    a^=1;
    arr.pb(mp(a,1));
    loop(i,1,n){
        cin >> a;
        a^=1;
        if(a == arr.rbegin()->first)arr.rbegin()->second++;
        else arr.pb(mp(a,1));
    }
    ll ans = 0;
    for(auto i: arr){
        if(i.first == 0)ans = max(ans,i.second);
    }
    if(arr.begin()->first == 0 && arr.rbegin()->first == 0)ans = max(arr.begin()->second+arr.rbegin()->second,ans);
    cout << ans;
    return 0;
}
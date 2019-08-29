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
#define MAXN 25
using namespace std;

void solve(){
    int n;
    cin >> n;
    V<int> a,b;
    loop(i,0,n){
        int lk;
        cin >> lk;
        a.pb(lk);
    }
    loop(i,0,n){
        int lk;
        cin >> lk;
        b.pb(lk);
    }
    int ans =0;
    for(int i = 0; i < n; ++i){
        int a1,a2;
        a2 = max(b[i],a[i]);
        a1 = min(a[i],b[i]);
        ans+=min(a1 + n - a2,a2-a1);
    }
    cout << ans;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
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

void solve(){
    int n;
    cin >> n;
    ll *arr = new ll[n];
    ll *psa = new ll[n+1];
    cin >> arr[0];
    // psa[0] = 1;
    psa[1] = arr[0];
    loop(i,1,n){
        cin >> arr[i];
        psa[i+1] = psa[i] + arr[i];
    }
    int ans = 0;
    ll i = 1;
    while(i < n){
        // cout << i << " ";
        ans++;
        i += psa[i];
    }

    // cout << "\n";
    cout << ans << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
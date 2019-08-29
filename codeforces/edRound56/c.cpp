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

int main(){
    FAST
    ll n;
    cin >> n;
    V<ll> b((n/2)+1);
    V<ll> a(n+1);
    cin >> b[1];
    a[1] = 0;
    a[n] = b[1];
    for(ll i = 2; i <= n/2; ++i){
        // cout << i << " " << n-i+1 << "\n";
        cin >> b[i];
        ll to_go_last = b[i]-a[i-1];
        ll to_go_front = a[i-1];
        if(to_go_last > a[n-i+2]){
            // cout << "HELLO\n";
            to_go_last = a[n-i+2];
            to_go_front = b[i]-to_go_last;
        }
        a[i] = to_go_front;
        a[n-i+1] = to_go_last;
        // for(int i = 1; i <= n; ++i){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
    for(ll i = 1; i <= n; ++i){
        cout <<  a[i] << " ";
    }
    return 0;
}
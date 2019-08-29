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

bool f(PLL a, PLL b, PLL c){
    PLL v1 = mp(b.F-a.F,b.S-a.S);
    PLL v2 = mp(c.F-b.F,c.S-b.S);
    ll res = v2.F*v1.S - v2.S*v1.F;
    return (res < 0);
}

int main(){
    int n;
    cin >> n;
    V<PLL> arr(n);
    loop(i,0,n){
        ll a,b;
        cin >> a >> b;
        arr[i] = mp(a,b);
    }
    ll ans = 0;
    loop(i,0,n){
        if(f(arr[i%n],arr[(i+1)%n],arr[(i+2)%n])){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
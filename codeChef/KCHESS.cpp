/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test long long int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopr(i,a,b) for(long long int i=a;i>=b;i--)
#define loops(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define ull unsigned long long long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<long long int, long long int>
#define PUU pair<unsigned long long long long int, unsigned long long long long int>
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
    map<pair<ll,ll>,int> arr;
    int n;
    cin >> n;
    while(n--){
        ll x,y;
        cin >> x >> y;
        arr[mp(x-1,y+2)] = 1;
        arr[mp(x-1,y-2)] = 1;
        arr[mp(x+1,y-2)] = 1;
        arr[mp(x+1,y+2)] = 1;
        arr[mp(x+2,y+1)] = 1;
        arr[mp(x+2,y-1)] = 1;
        arr[mp(x-2,y-1)] = 1;
        arr[mp(x-2,y+1)] = 1;
    }
    ll x,y;
    cin >> x >> y;
    if(arr[mp(x+1,y)] && arr[mp(x-1,y)] && arr[mp(x,y-1)] && arr[mp(x,y+1)]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    long long int t = 1;
    cin >> t;
    while(t--){solve();}
    return 0;
}
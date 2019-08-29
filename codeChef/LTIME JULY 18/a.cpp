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
#define S second
#define IT iterator
#define F first
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

void solve(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(abs(x-b) + abs(y-c) == a && x >= b && y >= c){
        cout << "YES\n";
        return;
    }
    if(abs(x-c) + abs(y-b) == a && x >= c && y >= b){
        cout << "YES\n";
        return;
    }
    if(abs(x-b) + abs(y-a) == c && x >= b && y >= a){
        cout << "YES\n";
        return;
    }
    if(abs(x-a) + abs(y-b) == c && x >= a && y >= b){
        cout << "YES\n";
        return;
    }if(abs(x-a) + abs(y-c) == b && x >= a && y >= c){
        cout << "YES\n";
        return;
    }
    if(abs(x-c) + abs(y-a) == b && x >= c && y >= a){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
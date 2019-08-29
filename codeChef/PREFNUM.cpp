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
    ll x,y;
    cin >> x >> y;
    ll t = x;
    if(x%y == 0){
        cout << x << "\n";
        return;
    }
    int dig = 0;
    bool only10 = true;
    while(t){
        if(t%10 != 0 && t != 1)only10 = false;
        dig++;
        t/=10;
    }
    t = x;
    ll o = 1;
    for(int i = 1; i+dig <= 18; ++i){
        o *= 10;
        t=x*o;
        if(t%y == 0){
            cout << t << "\n";
            return;
        }
        ll rem = y - (t%y);
        if(rem < o){
            cout << t+rem << "\n";
            return;
        }
    }
    if(only10 && (1000000000000000000 % y == 0)){
        cout << "1000000000000000000\n";
        return;
    }
    cout << -1 << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
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
    V<int> o;
    V<int> e;
    int n;
    cin >> n;
    loop(i,0,n){
        int a;
        cin >> a;
        if(a%2)o.pb(a);
        if(a%2 == 0)e.pb(a);
    }
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    if(o.size() < 2 && e.size() < 2){
        cout << "0\n";
    }
    else if(o.size() < 2){
        cout << e[e.size()-1]+e[e.size()-2] << "\n";
    }
    else if(e.size() < 2){
        cout << o[o.size()-1]+o[o.size()-2] << "\n";
    }else{
        cout << max(o[o.size()-1]+o[o.size()-2],e[e.size()-1]+e[e.size()-2]) << "\n";
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
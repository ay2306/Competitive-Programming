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

bool comp(PLL a, PLL b){
    if(a.F - a.S > b.F - b.S)return false;
    if(a.F - a.S < b.F - b.S)return true;
    return a.F < b.F;
}
int main(){
    int n,m,k;
    cin >> n >> m  >> k;
    priority_queue<ll> p;
    loop(i,0,n){
        ll a;
        cin >> a;
        p.push(a);
    }
    while(p.size() > k)p.pop();
    priority_queue<PLL,V<PLL>,function<bool(PLL,PLL)> > p1(comp);
    loop(i,0,m){
        ll a,b;
        cin >> a >> b;
        p1.push(mp(a,b));
    }
    ll cost = 0;
    while(p.size()){
        if()
    }
    return 0;
}

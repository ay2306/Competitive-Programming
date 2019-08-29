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
ll n,d;
unordered_map<int,ll> m;
void addD(ll a, ll c);
void getDig(ll a, ll c);

void addD(ll a, ll c){
    if(a < 10)m[a] = min(m[a],c);
    if(c == 15)return;
    addD(a+d,c+1,arr);
    getDig(a+d,c+1,arr);
}

void getDig(ll a, ll c){
    if(a < 10)m[a] = min(m[a],c);
    if(c == 15)return ;
    ll s = 0;
    while(a){
        s+=(a%10);
        a/=10;
    }
    addD(s,c+1,arr);
    getDig(s,c+1,arr);
}
void solve(){
    for(int i = 1; i < 9 ;++i){
        m[i] = 200;
    }
    cin >> n >> d;
    ll a = n;
    addD(a,1,v);
    getDig(a,1,v);
    int ans = 0;
    for(int i = 1; i < 9; ++i){
        if(m[i] != 200){
            cout << i << " " << m[i]-1 << "\n";
            return;
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
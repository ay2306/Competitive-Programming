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

ll n,h;
V<ll> arr;
bool check(ll k){
    ll h1,h2;
    h1 = h;
    h2 = h1;
    // cout<<"CASE " << k << "\n";
    priority_queue<ll,V<ll> > p;
    for(int i = 0; i < k; ++i)p.push(arr[i]);
    ll ans = 0;
    // cout << h1 << " " << h2 << "\n";
    while(p.size()){
        if(h1 < p.top())return false;
        h1-=p.top();
        p.pop();
        // cout << h1 << " " << h2 << "\n";
        if(p.size() == 0)return true;
        if(h2 < p.top())return false;
        h2-=p.top(); 
        p.pop();
        // cout << h1 << " " << h2 << "\n";
        ll a = min(h1,h2);
        h1 = a;
        h2 = a;
    }
    return true;
}


int main(){
    cin >> n >> h;
    arr = V<ll> (n);
    loop(i,0,n)cin >> arr[i];
    ll ans = 0;
    ll low = 0;
    ll high = n;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid)){
            ans = max(mid,ans);
            low = mid+1;
        }else{
            high =  mid-1;
        }
    }
    cout << ans;
    return 0;
}
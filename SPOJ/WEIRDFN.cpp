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
#define ll unsigned long long int
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
    ll a,b,c,n;
    cin >> a >> b >> c >> n;
    V<ll> arr(n+10);
    arr[0] = 0;
    arr[1] = 1;
    priority_queue<ll,V<ll>,greater<ll> > right;
    priority_queue<ll,V<ll> > left;
    arr[2] = (a+b+b+c)%MOD;
    left.push(min(arr[1],arr[2]));
    right.push(max(arr[1],arr[2]));
    for(int i = 3; i <= n; ++i){
        ll med = left.top();
        arr[i] = (a*med + b*i + c)%MOD;
        if(arr[i] >= left.top()){
            right.push(arr[i]);
        }else{
            left.push(arr[i]);
        }
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }else if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
    }
    ll s = 0;
    loop(i,1,n+1)s+=arr[i];
    cout << s << "\n";
}


int main(){
 
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
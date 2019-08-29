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

int main(){
    ll n;
    cin >> n;
    V<ll> arr(n,1);
    V<ll> q(n-1);
    loop(i,0,n-1){
        cin >> q[i];
        arr[i+1] = arr[i] + q[i];
    }
    ll s = abs(accumulate(q.begin(),q.end(),0));
    if(s >= n){
        cout << -1 ;
        return 0;
    }
    // cout << s << "\n";
    ll mn = *min_element(arr.begin(),arr.end());
    if(mn < 1){
        loop(i,0,n)arr[i]+=(1-mn);
    }
    // ll mx = *max_element(arr.begin(),arr.end());
    // if(mx > n){
    //     loop(i,0,n)arr[i]+=(n-mx);
    // }
    for(auto i: arr){
        if(i < 1 || i > n){
            cout << "-1";
            return 0;
        }
    }
    unordered_map<ll,int> m;
    for(auto i: arr){
        if(m[i] > 0 || i < 1){
            cout << "-1";
            return 0;
        }
        m[i]++;
    }
    for(auto i: arr)cout << i << " ";
    return 0;
}
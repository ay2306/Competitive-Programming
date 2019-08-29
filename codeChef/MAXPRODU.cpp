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
    ll n,k;
    cin >> n >> k;
    ll s = k*(k+1)/2;
    if(s > n){
        cout << "-1\n";
        return;
    }else if(s == n || s+k > n){
        cout << "0\n";
        return;
    }
    V<ll> arr(k);
    loop(i,0,k)arr[i] = i+2;
    ll rem = n - (s+k);
    loop(i,0,k){
        arr[i] += (rem/k);
    }
    rem%=k;
    loopr(i,k-1,0){
        if(rem){arr[i]++;rem--;}
        else break;        
    }
    ll ans = 1;
    loop(i,0,k){
        ans = (ans * ((arr[i]*(arr[i]-1))%MOD))%MOD;
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
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
    ll n,k;
    cin >> n >> k;
    V<ll> arr(n);
    ll s = 0;
    loop(i,0,n){cin >> arr[i];s+=arr[i];}
    sort(arr.begin(),arr.end());
    ll s1 = 0, s2 = 0;
    loop(i,0,k)s1+=arr[i];
    for(int i = n-1; i >= n-k; --i)s2+=arr[i];
    if(s-s2 <  s1){
        cout << s2 - (s-s2) << endl;
    }else{
        cout << s-s1 - s1 << endl;
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
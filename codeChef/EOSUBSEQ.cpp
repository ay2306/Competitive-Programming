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
    int n,k;
    cin >> n >> k;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    V<PLL> a(n,make_pair(0,0));
    for(int i = 0; i < n; ++i){
        if(arr[i]%2 == 1){
            if(i > 0)a[i]=a[i-1];
        }else{
            if(i - (k+1) >= 0){
                a[i].first = max(a[i-(k+1)].first,a[i-(k+1)].second) + arr[i];
            }else{
                a[i].first = arr[i];
            }
            if(i > 0){
                a[i].second = max(a[i-1].first,a[i-1].second);
            }else{
                a[i].second = 0;
            }
                
        }
    }
    // for(int i = 0; i < n; ++i){
    //     cout << "(" << arr[i] << ", " << a[i].F << ", " << a[i].S << ")\n";
    // }
    // cout << "_____________________________\n";
    ll s1 = max(a[n-1].F,a[n-1].S);
    a = V<PLL> (n,make_pair(0,0));
    for(int i = 0; i < n; ++i){
        if(arr[i]%2 == 0){
            if(i > 0)a[i]=a[i-1];
        }else{
            if(i - (k+1) >= 0){
                a[i].first = max(a[i-(k+1)].first,a[i-(k+1)].second) + arr[i];
            }else{
                a[i].first = arr[i];
            }
            if(i > 0){
                a[i].second = max(a[i-1].first,a[i-1].second);
            }else{
                a[i].second = 0;
            }
                
        }
    }
    // for(int i = 0; i < n; ++i){
    //     cout << "(" << arr[i] << ", " << a[i].F << ", " << a[i].S << ")\n";
    // }
    ll s2 = max(a[n-1].F,a[n-1].S);
    
    cout << s1+s2 << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
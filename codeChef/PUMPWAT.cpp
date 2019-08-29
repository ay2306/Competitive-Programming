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
int n;
ll *arr;

int fsolve(int l, int r){
    if(l < 0 || r >= n)return INT_MAX;
    unordered_map<ll,int> m;
    int xi = l;
    for(int i = l; i <= r; ++i){
        m[arr[i]]++;
        if(arr[xi] < arr[i]){
            xi = i;
        }
    }
    if(m[arr[xi]] > 1)return m[arr[xi]];
    if(xi == l || xi == r)return 1;
    return min(fsolve(xi+1,r),fsolve(l,xi-1))+1;
}

void solve(){
    cin >> n;
    arr = new ll[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];    
    }
    int k = n;
    int ans = fsolve(0,n-1);
    cout << ans << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
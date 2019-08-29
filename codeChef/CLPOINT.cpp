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
    ll arr[100100][5];
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; ++i)for(int j = 0; j < p; ++j)cin >> arr[i][j];
    ll ans = 0;
    ll ind = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < p; ++j)ans+=abs(arr[0][j]-arr[i][j]);
    }
    for(int i = 1; i < n; ++i){
        ll tmp = 0;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < p; ++k)tmp+=abs(arr[i][k]-arr[j][k]);
        }
        if(tmp < ans){
            ind = i;
            ans = tmp;
        }
    }
    for(int i = 0; i < p; ++i)cout << arr[ind][i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
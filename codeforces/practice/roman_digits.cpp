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
ull dp[10];
int *arr;
ST<ll> ans;
ll solve(int n){
    for(ll j = 1; j <= n; ++j){
        ST<ll> tmp;
        for(ST<ll>::IT it = ans.begin(); it != ans.end(); ++it){
            for(int i = 0; i < 4; ++i){
                tmp.insert(arr[i] + *it);
            }
        }
        ans.clear();
        ans = tmp;
    }
    cout << ans.size();
}
int main(){
    // FILE_READ
    arr = new int[4];
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 10;
    arr[3] = 50;
    ans.insert(0);
    ll n;
    cin >> n;
    solve(n);
    return 0;
}
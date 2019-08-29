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
// ull dp[10];
// int *arr;
// ST<ll> ans;
// ll solve(int n){
//     for(int j = 1; j <= n; ++j){
//         ST<ll> tmp;
//         for(ST<ll>::IT it = ans.begin(); it != ans.end(); ++it){
//             for(int i = 0; i < 4; ++i){
//                 tmp.insert(arr[i] + *it);
//             }
//         }
//         ans.clear();
//         ans = tmp;
//         // for(ST<ll>::IT it = ans.begin(); it != ans.end(); ++it)cout << *it << " ";
//         // cout << endl;
//         // cout << j << " : " << ans.size()  << " " << ans.size() + 49 << endl;
//         cout << ans.size() << ",";
//     }
// }
int main(){
    // FILE_READ
    ll arr[] = {0,4,10,20,35,56,83,116,155,198,244,292,341};
    ll n;
    cin >> n;
    if(n < 12)cout << arr[n];
    else{
        ll k = n-12;
        ll p = ((k*49)%LLONG_MAX + arr[12]%LLONG_MAX)%LLONG_MAX;
        cout << p;
    }
    // ans.insert(0);
    // solve(12);
    return 0;
}
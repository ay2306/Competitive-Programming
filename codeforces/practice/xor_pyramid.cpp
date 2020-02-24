#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

// unordered_map<int,vector<int>> m;

// void checking(vector<vector<int>> &a){
//     if(a.size() == 1){
//         for(auto &i: a[0])cout << i << " ";
//         cout << "\n";
//         return;
//     }
//     int i = 1;
//     vector<vector<int>> arr;
//     while(i < a.size()){
//         map<int,int> m;
//         for(auto &j: a[i-1])m[j]++;
//         for(auto &j: a[i])m[j]++;
//         vector<int> k;
//         for(auto &j: m)if(j.second & 1)k.emplace_back(j.first);
//         arr.emplace_back(k);
//         i++;
//     }
//     checking(arr);
// }

// void brute_check(int n){
//     vector<vector<int>> arr;
//     loop(i,1,n+1)arr.emplace_back(vector<int>(1,i));
//     checking(arr);
// }

const int N = 5010;

ll dp[N][N];
ll a[N];
int main(){
    FAST
    // FILE_READ_OUT
    int n;
    cin >> n;
    loop(i,0,n)cin >> a[i];
    // brute_check(n);
    loop(i,0,n){
        dp[0][i] = a[i];
    }
    loop(i,1,n){
        loop(j,0,n-i+1){
            dp[i][j] = dp[i-1][j+1] ^ dp[i-1][j];
        }
    }
    loop(i,1,n){
        loop(j,0,n-i+1){
            dp[i][j] = max({dp[i][j],dp[i-1][j+1],dp[i-1][j]});
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << dp[r-l][l-1] << "\n";
    }
   return 0;
}
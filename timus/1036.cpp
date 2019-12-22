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
/*
 * This is classical dp question
 ! No need to solve mathematics
 * dp[positions][state][current_sum]
 * positions can never be over 50 (as mentioned )
 ? state are only 2 possible: either equal or smaller but there is no number to compare so find out possible sum to be S?
 * * This saves the second state position, N and sum needs to be S
 * Thus dp[postions][sum]
 */
//
ll dp[100][2000];
int N,S;
ll calculate(int position = 0, int sum = 0){
    if(position == N){
        if(sum == S){
            return 1;
        }
        return 0;
    }
    if(sum > S)return 0;
    ll &res = dp[position][sum];
    if(res != -1)return res;
    res = 0;
    loop(i,0,10){
        // number[position] = i;
        res+=calculate(position+1,sum+i);
    }
    return res;
}

int main(){
    cin >> N >> S;
    if(S & 1){
        cout << 0;
    }else{
        S>>=1;
        memset(dp,-1,sizeof(dp));
        ll a = calculate();
        cout << a*a;
    }
    return 0;
}
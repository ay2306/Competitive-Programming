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

const int N = 1 << 18;
string a;
int m;
int n;
ll dp[101][N];
int ppp[50];
ll power(ll a,ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n/2);
    p *= p;
    p%=m;
    if(n%2){
        p *= a;
        p%=m;
    }
    return p;
}

ll cal(ll bits,ll mod){
    bitset<18> b = bits;
    int pos = b.count();
    if(pos == n){
        if(mod%m == 0)return 1;
        return 0;
    }
    if(dp[mod][bits] != -1)return dp[mod][bits];
    ll res = 0;
    V<bool> visited(10,false);
    loop(i,0,a.size()){
        if(visited[a[i]-'0'] || b[i] || (pos == 0 && a[i] == '0'))continue;
        ll newMod = a[i] - '0';
        newMod*=ppp[n-pos-1];
        newMod+=mod;
        newMod%=m;
        visited[a[i]-'0'] = true;
        res+=cal(bits|(1 << i),newMod);
    }
    dp[mod][bits] = res;
    return dp[mod][bits];
}

int main(){
    // FAST
    cin >> a >> m;
    loop(i,0,20){
        ppp[i] = power(10,i);
    }
    n = a.size();
    memset(dp,-1,sizeof(dp));
    cout << cal(0,0);
    return 0;
}
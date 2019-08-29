/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 998244353
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
const ll mod = 998244353;
ll dp[20][1024][2];

vector<int> num;
ll l,r,k;
ll p[20];
ll ans = 0;

ll solve(int pos, int bits, int f, ll s){
    if(pos == num.size()){
        bitset<20> bit = bits;
        if(bit.count() > k)return 0;
        return s;
    }
    if(dp[pos][bits][f])
}

int main(){
    ll o = 1;
    loop(i,0,20){
        o%=mod;
        p[i] = o;
    }
    cin >> l >> r;
    while(r){
        num.pb(r%10);
        r/=10;
    }
    reverse(num.begin(),num.end());
    ll s1 = solve(0,0,0,0);
    return 0;
}
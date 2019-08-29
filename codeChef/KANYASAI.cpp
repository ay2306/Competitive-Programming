/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include<bits/stdc++.h> 
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
vector<int> num;
ll dp[20][2][2][2];

ll call(int pos, int f, int fv, int sv){
    if(pos == num.size()){
        if(fv && sv)return 1;
        return 0;
    }
    if(dp[pos][f][fv][sv] != -1)return dp[pos][f][fv][sv];
    ll res = 0;
    ll LMT;
    if(f==0){
        LMT = num[pos];
    }else{
        LMT = 9;
    }
    for(int dgt = 0; dgt <= LMT; ++dgt){
        int nf = f;
        int nfv = fv;
        int nsv = sv;
        if(f == 0 && dgt < LMT)nf = 1;
        if(dgt == 5)nfv = 1-fv;
        if(dgt == 7)nsv = 1-sv;
        res+=call(pos+1,nf,nfv,nsv);
    }
    dp[pos][f][fv][sv] = res;
    return dp[pos][f][fv][sv];
}

ll solve1(ll b){
    num.clear();
    while(b){
        num.pb(b%10);
        b/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    ll ans = call(0,0,0,0);
    return ans;
}

void solve(){
    ll a,b;
    cin >> a >> b;
    // ll c = solve1(b);
    // ll d = solve1(a);
    // cout << c << " " << d << "\n";
    cout << solve1(b)-solve1(a-1) << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
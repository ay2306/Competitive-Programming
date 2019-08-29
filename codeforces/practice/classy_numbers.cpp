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

ll dp[20][2][4];
V<int> num;

ll cal(int pos, int f, int mask){
    if(mask == 4)return 0;
    if(pos == num.size()){
        if(mask == 0)return 0;
        int k = mask/2;
        int c = 0;
        while(k){
            c+=(k%2);
            k/=2;
        }
        if(c > 3)return 0;
        return 1;
    }
    if(dp[pos][f][mask] != -1)return dp[pos][f][mask];
    int LM;
    if(f == 0)LM = num[pos];
    else LM = 9;
    ll res = 0;
    for(int i = 0; i <= LM; ++i){
        int k = mask;
        if(i > 0)k++;
        if(f == 0 && i == LM)res+=cal(pos+1,0,k);
        else res+=cal(pos+1,1,k);
    }
    dp[pos][f][mask] = res;
    return res;
}

void solve(){
    ll a,b;
    num.clear();
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    a--;
    ll op = a;
    while(a){
        num.pb(a%10);
        a/=10;
    }
    reverse(num.begin(),num.end());
    ll s1 = 0;
    if(op)s1 = cal(0,0,0);
    num.clear();
    memset(dp,-1,sizeof(dp));
    while(b){
        num.pb(b%10);
        b/=10;
    }
    reverse(num.begin(),num.end());
    ll s2 = cal(0,0,0);
    // cout << s1 << "  " << s2 << "\n";
    cout << s2-s1 << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
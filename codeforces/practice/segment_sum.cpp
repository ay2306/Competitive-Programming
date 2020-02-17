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
#define all(a) a.begin(), a.end()
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
const ll mod = 998244353;
ll dp[20][(1<<10)][2];
V<int> num;
int k;
ll fn(int pos = 0, int mask = 0, int comp = 0){
    if(pos == num.size()){
        // cout << mask << "\n";
        return (__builtin_popcount(mask) < k && mask > 0);
    }
    ll &res = dp[pos][mask][comp];
    if(res != -1)return res;
    res = 0;
    int last = 9;
    if(comp == 0){
        last = num[pos];
    }
    loop(i,0,last){
        if(comp == 0 && i == last)res+=fn(pos+1,(mask|(1<<i)),0);
        else res+=fn(pos+1,(mask|(1<<i)),1);
        if(res >= mod)res-=mod;
    }
    return res;
}

void pre(){
    loop(i,0,20){
        loop(j,0,(1<<10)){
            loop(k,0,2){
                dp[i][j][k] = -1;
            }
        }
    }
}

int main(){
    ll l,r;
    cin >> l >> r >> k;
    l--;
    pre();
    while(r){
        num.pb(r%10);
        r/=10;
    }
    reverse(all(num));
    ll s1 = fn();
    num.clear();
    ll s2 = 0;
    pre();
    if(l){
        while(l){
            num.pb(l%10);
            l/=10;
        }
        reverse(all(num));
        s2 = fn();
    }
    cout << s1 << " " << s2 << "\n";
    cout << (s1-s2+mod)%mod;
    return 0;
}
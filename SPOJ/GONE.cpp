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

V<int> num;
ll dp[10][200][2];
int prime[200];
ll cal(int pos, int sum, int f){
    if(pos == num.size()){
        if(prime[sum] == 0)return 1;
        return 0;
    }
    if(dp[pos][sum][f] != -1)return dp[pos][sum][f];
    int LM;
    if(f == 0){
        LM = num[pos];
    }else{
        LM = 9;
    }
    ll res = 0;
    for(int i = 0; i <= LM; ++i){
        if(i == num[pos] && f == 0)res+=cal(pos+1,sum+i,0);
        else res+=cal(pos+1,sum+i,1);
    }
    dp[pos][sum][f] = res;
    return dp[pos][sum][f];
}

ll solve1(ll a){
    num.clear();
    while(a){
        num.pb(a%10);
        a/=10;
    }
    memset(dp,-1,sizeof(dp));
    reverse(num.begin(),num.end());
    return cal(0,0,0);
}

void solve(){
    ll a,b;
    cin >> a >> b;
    a = solve1(a-1);
    b = solve1(b);
    // cout << b << " " <<  a << " ";
    cout <<  b-a << "\n";
}

int main(){
    for(int i = 2; i < 200; ++i){
        if(prime[i] == 0){
            for(int j = 2; i*j < 200; ++j){
                prime[i*j]++;
            }
        }
    }
    prime[0] = 1;
    prime[1] = 1;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
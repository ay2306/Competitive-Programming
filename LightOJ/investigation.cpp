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
vector<int> num;
ll dp[20][1010][1010][2];
int k;

ll reme[20];


ll bme(ll a, ll n){
    if(n == 0)return 1;
    if(n==1)return a%k;
    ll p = bme(a,n/2);
    p*=p;
    if(n%2==1){
        p*=a;
    }
    p = p%k;
    return p;
}

ll call(int pos, int drem, int rem, int f){
    if(pos == num.size()){
        if(rem == 0 && drem == 0)return 1;
        return 0;
    }
    if(dp[pos][drem][rem][f] != -1)return dp[pos][drem][rem][f];
    int LM;
    if(f)LM=9;
    else LM = num[pos];
    ll res = 0;
    for(int i = 0; i <= LM; ++i){
        int nrem = (drem+i)%k;
        int krem = ((i%k)*(reme[num.size()-1-pos]%k))%k;
        krem = (krem%k + rem%k)%k;
        if(i == LM)res+=call(pos+1,nrem,krem,0);
        else res+=call(pos+1,nrem,krem,1);
    }
    dp[pos][drem][rem][f] = res;
    return res;
}



ll solve(ll a){
    num.clear();
    while(a){
        num.pb(a%10);
        a/=10;
    }
    memset(dp,-1,sizeof(dp));
    reverse(num.begin(),num.end());
    return call(0,0,0,0);
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b >> k;
        for(int i = 0; i < 2010; ++i){
            reme[i] = bme(10,i);
        }
        cout << solve(b)-solve(a-1) << "\n";
    }
    return 0;
}
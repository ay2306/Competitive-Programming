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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

const ll maxn = 1e5+10;
ll dp[maxn], pref[maxn];
int main(){
   ll t,k;
   cin >> t >> k;
   dp[0] = 1;
   loop(i,1,maxn){
        if(i-k < 0)dp[i] = dp[i-1]%MOD;
        else{
           dp[i] = (dp[i-k]%MOD + dp[i-1]%MOD)%MOD;
        }
        pref[i] = (pref[i-1] + dp[i])%MOD;
   }
   while(t--){
       ll a,b;
       cin >> a >> b;
       cout << (pref[b]-pref[a-1]+MOD)%MOD << "\n";
   }
   return 0;
}
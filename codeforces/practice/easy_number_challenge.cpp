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
#define mod 1073741824
using namespace std;
const ull MAX = 1000001;
int main(){
    ull arr[MAX] = {0};
    for(int i = 1; i <= MAX; ++i)for(int j = 1; j*i <= MAX; ++j)arr[i*j]++;
    ull a,b,c,ans = 0;
    cin >> a >> b >> c;
    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= b; ++j){
            for(int k = 1; k <= c; ++k){
                ans = (((ans%mod)+(arr[i*j*k]%mod))%mod);
            }
        }
    }
    cout << ans%mod;
    return 0;
}
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
#define MAX 100000
using namespace std;

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    int *v = new int[MAX+1];
    for(int i = 0; i < n; ++i){cin >> a[i];}
    sort(a,a+n);
    ll *dp = new ll[MAX+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= MAX; ++i){
        init(v,0);
        for(int j = 0; j < n && a[j] <= i; ++j){
            if(!v[i]){
                dp[i]+=(dp[i-a[j]] * dp[a[j]]);
                v[a[j]] = 1;
                v[i-a[j]] = 1;
            }
        }
    }   
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        for(int i = 1; i <= t; ++i)cout << dp[i] << " ";
        cout << endl;
        cout << dp[t] << endl;
    }
    return 0;
}
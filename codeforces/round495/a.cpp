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

ll dis(ll a, ll b){
    if(a>b)return a-b;
    return b-a;
}



int main(){
    // freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    ll d;
    cin >> d;
    ll *a = new ll[n];
    ll ans = 0;
    for(int i = 0; i < n; ++i)cin >> a[i];
    sort(a,a+n);
    ans+=2;
    M<ull,int> m;
    for(int i = 0; i+1 < n; ++i){
        if((a[i]+d) == (a[i+1]-d))ans++;
        if((a[i]+d) < (a[i+1]-d))ans+=2;    
    }
    cout << ans;
    return 0;
}
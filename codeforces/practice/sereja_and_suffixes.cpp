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

int main(){
    // freopen("input.txt","r",stdin);    
    ll n,a;
    M<ll,ll> m;
    ll q;
    cin >> n;
    cin >> q;
    ll *ans = new ll[n];
    ll *arr = new ll[n];
    // cin >> a;
    // m.insert(mp(a,1));
    // ans[0] = 1;
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
    // cout << "CHE";
    m.insert(mp(arr[n-1],1));
    ans[n-1] = 1;
    for(ll i = n-2; i >= 0; --i){
        if(m.count(arr[i]) == 0){
            ans[i] = ans[i+1] + 1;
            m.insert(mp(arr[i],1));
        }else{
            ans[i] = ans[i+1];
        }
    }
    while(q--){
        ll l;
        cin >> l;
        // cout << "HELLO";
        cout << ans[l-1] << endl;
    }
    return 0;
}
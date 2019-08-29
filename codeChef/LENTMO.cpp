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
#define all(container) container.begin(),container.end()
#define total(container) accumulate(container.begin(),container.end(),0*1LL)
#define MAXN 25
using namespace std;


void solve(){
    ll n;
    cin >> n;
    V<ll> arr(n);
    ll ans = 0;
    loop(i,0,n){
        cin >> arr[i];
        ans+=arr[i];
    }
    ll k,x;
    cin >> k >> x;
    V<ll> more;
    V<ll> less;
    loop(i,0,n){
        ll d = (arr[i]^x);
        d-=arr[i];
        if(d > 0){
            more.pb(d);
        }else{
            less.pb(-d);
        }
    }
    // printf("MORE = ");
    // for(auto &i: more)printf("%lld  ",i);
    // printf("\n");
    // printf("LESS = ");
    // for(auto &i: less)printf("%lld  ",i);
    // printf("\n");
    if(more.size() == 0){
        cout << ans << "\n";
        return;
    }
    sort(all(more));
    sort(all(less));
    // printf("SUM = %lld\n",total(more));
    // printf("SUM_ARR = %lld\n",ans);
    if(k == 1){
        cout << ans + total(more) << "\n";
        return ;
    }
    if(n == k){
        cout << max(ans+total(more)-total(less),ans) << "\n";
        return;
    }
    if((more.size() % k)%2 == 0){
        cout << ans + total(more) << "\n";
        return;
    }else{
        if(k%2 == 1){
            cout << ans + total(more) << "\n";
            return;
        }else{
            // printf("CURR = %lld\n",ans);
            ans += (total(more));
            // printf("CURR = %lld\n",ans);
            ans -= more[0];
            // printf("CURR = %lld\n",ans);
            if(less.size() > 0){
                ans += max(0*1LL,more[0]-less[0]);
            }
            cout << ans << "\n";
            return ;
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
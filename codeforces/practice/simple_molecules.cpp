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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first <= b.first)return true;
    return false;
}

int main(){
    pair<ll,ll> a[3]; 
    ll x,y,z;
    ll tmp[3];
    cin >> x >> y >> z;
    tmp[0] = x;
    tmp[1] = y;
    tmp[2] = z;
    a[0] = mp(x,0);
    a[1] = mp(y,5);
    a[2] = mp(z,50);
    sort(a,a+3,cmp);
    swap(a[1],a[2]);
    ll ans[3];
    // if(a[1].first == a[0].first + a[2].first){
    //     pair<ll,ll> ans[3];
    //     ans[0]=mp(a[0].second,a[1].first-a[2].first);
    //     ans[1]=mp(a[1].second,a[1].first-a[0].first);
    //     ans[2]=mp(a[2].second,0);
    //     sort(ans,ans+3);
    //     cout << ans[0].second << " " << ans[1].second << " " << ans[2].second;
    //     return 0;
    // }
    x = (a[0].first+ a[1].first - a[2].first)/2;
    y = (a[2].first+ a[1].first - a[0].first)/2;
    z = (a[0].first+ a[2].first - a[1].first)/2;
    ll t;
    t = a[0].second + a[1].second;
    if(t == 5){
        ans[0]=x;
    }else if(t == 50){
        ans[2]=x;
    }else{
        ans[1] = x;
    }
    t = a[1].second + a[2].second;
    if(t == 5){
        ans[0]=y;
    }else if(t == 50){
        ans[2]=y;
    }else{
        ans[1] = y;
    }
    t = a[0].second + a[2].second;
    if(t == 5){
        ans[0]=z;
    }else if(t == 50){
        ans[2]=z;
    }else{
        ans[1] = z;
    }
    ll p = 0;
    for(int i = 0; i < 3; ++i)if(ans[i] == 0)p++;
    if(ans[0] < 0 || ans[1] < 0 || ans[2] < 0 || p > 1){
        cout << "Impossible";
        return 0;
    }
    if(tmp[0] != ans[0] + ans[2]){
        cout << "Impossible";
        return 0;
    }
    if(tmp[1] != ans[0] + ans[1]){
        cout << "Impossible";
        return 0;
    }
    if(tmp[2] != ans[1] + ans[2]){
        cout << "Impossible";
        return 0;
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
    
    return 0;
}
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
    int a,n,k,z=0;
    ll s = 0;
    cin >> n >> k;
    V<int> neg,pos;
    for(int i = 0; i < n; ++i){
        cin >> a;
        // s+=a;
        if(a < 0)neg.pb(a);
        if(a > 0)pos.pb(a);
        if(a==0)z++;
    }
    // cout << s;
    // sort(neg.begin(),neg.end());
    for(int i = 0; i < neg.size() && k; ++i,--k){
        neg[i]*=-1;
    }
    ll ans = 0;
    if(k){
        if(z || k%2 == 0){
            for(int i = 0; i < neg.size(); ++i)ans+=neg[i];
            for(int i = 0; i < pos.size(); ++i)ans+=pos[i];
        }else{
            for(int i = 0; i < neg.size(); ++i)pos.pb(neg[i]);
            // for(int i = 0; i < pos.size(); ++i)ans+=pos[i];
            sort(pos.begin(),pos.end());
            for(int i = 0; i < pos.size(); ++i)ans+=pos[i];
            // cout << pos.size() << endl;
            // cout << ans << endl;
            // cout << ans << " - " << pos[0] << " = ";
            ans-=(2*pos[0]);
            // for(int i = 0; i < pos.size(); ++i)cout << pos[i] << " ";
            // cout << endl;
        }
    }else{
        for(int i = 0; i < neg.size(); ++i)ans+=neg[i];
        for(int i = 0; i < pos.size(); ++i)ans+=pos[i];
    }
    cout << ans;
    return 0;
}
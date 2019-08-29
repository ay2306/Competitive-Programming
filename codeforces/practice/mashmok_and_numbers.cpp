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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    ll n,k,i,d,f=2;
    V<ll> ans,p;
    int sv[100000] = {0};
    cin >> n >> k;
    if(n == 1 && k == 0){
        cout << "1";
        return 0;
    }
    if(n == 1){
        cout << "-1";
        return 0;
    }
    if((n/2) > k){
        cout << "-1";
        return 0;
    }
    d = k + 1;
    d-=n/2;
    ans.pb(d);
    ans.pb(d*2);
    k = 0;
    if(d <= 0){
        cout << "-1";
        return 0;
    }
    for(int i = 2; i < n;){
        ++k;
        if(k == d || k == d*2)continue;
        ans.pb(k);
        ++i;
    }
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    } 
    return 0;
}
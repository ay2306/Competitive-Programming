#include <bits/stdc++.h>
#define MOD 998244353
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

ll po[1001000];

ll modPower(ull a, ull n){
    // cout << n << endl;
    if(po[n] != 0)return po[n]%MOD;
    if(n%2 == 0){
        po[n] = (modPower(((a%MOD)*(a%MOD))%MOD,n/2)%MOD*modPower(((a%MOD)*(a%MOD))%MOD,n/2)%MOD)%MOD;
        return po[n]%MOD;
    }else{
        po[n] =   ((a%MOD)*(modPower(a,n-1)%MOD))%MOD;
        return po[n]%MOD;
    }
    // return po[n]%MOD;
}

int main(){
    FAST
    int n;
    cin >> n;
    ll *arr = new ll[n];
    for(int i = n-1; i >= 0;--i)cin >> arr[i];
    ll p2 = 1;
    ll ans = arr[0];    
    for(int i = 1; i < n; ++i){
        ans = (ans%MOD + (p2*(((i+2)*arr[i]%MOD)%MOD)%MOD))%MOD;
        p2 = (p2%MOD * 2%MOD)%MOD;
    }
    cout << ans;
    return 0;
}
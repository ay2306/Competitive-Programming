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
    ll x,y,n;
    cin >> x >> y >> n;
    int k = n%6;
    ll ans;
    switch(k){
        case 1: ans = x; break;
        case 2: ans = y; break;
        case 3: ans = y-x; break;
        case 4: ans = -1*x; break;
        case 5: ans = -1*y; break;
        case 0: ans = x-y; break;
    }
    if(ans < 0){
        cout << (MOD-((ans*-1)%MOD))%MOD;
        return 0;
    }
    cout << ans%MOD;
    return 0;
}
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int main(){
    ll n,l,a;
    cin >> n >> l >> a;
    PLL *arr = new PLL[n];
    loop(i,0,n){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    sort(arr,arr+n);
    ll last = 0;
    ll current = 0;
    ll ans = 0;
    loop(i,0,n){
        current = arr[i].first;
        ans+=((current-last)/a);
        last = current+arr[i].second;
    }
    current = l;
    ans+=((current-last)/a);
    cout << ans;
    return 0;
}
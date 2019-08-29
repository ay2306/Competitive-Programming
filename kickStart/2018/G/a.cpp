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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.out","w",stdout);
#define MAXN 25
using namespace std;

void solve(){
    static int c = 1;
    unordered_map<ll,int> m;
    unordered_map<ll,int> m1;
    int n;
    cin >> n;
    int ans = 0;
    vector<ll> arr(n);
    set<ll> p;
    loop(i,0,n){cin >> arr[i];m[arr[i]]++;p.insert(arr[i]);}
    int z = 0;
    for(auto i: p)arr[z++]=i;
    n = p.size();
    if(m[1] > 2){
        ans+=((m[1]*(m[1]-1)*(m[1]-2))/6);
    }
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if((m[arr[i]] == 1 && i == j) || (arr[i] == 1 && i==j))continue;
            if(arr[i] == 1 && m[arr[i]] == 1)continue;
            if(i == j){
                ans+=(((m[arr[i]]*(m[arr[i]]-1))/2)*(m[arr[i]*arr[i]]));
            }else{
                ans+=(m[arr[i]]*m[arr[j]]*m[arr[i]*arr[j]]);
            }
            // cout << arr[i] << " " << arr[j] << " " << arr[i]*arr[j] << " " << ans << "\n";
        }
    }
    printf("Case #%d: %d\n",c++,ans);
}

int main(){
    FILE_READ
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
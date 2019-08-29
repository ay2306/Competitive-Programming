#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);


int main(){
    int n;
    cin >> n;
    V<bool> visited(n+1,false);
    V<int> arr(n+1);
    loop(i,1,n+1){
        cin >> arr[i];
    }
    V<V<int>> a;
    loop(i,1,n+1){
        unordered_map<int,int> m;
        if(visited[i])continue;
        int cur = i;
        V<int> ans;
        while(1){
            visited[cur] = true;
            m[cur]++;
            ans.pb(cur);
            if(m[cur] > 1)break;
            cur = arr[cur];
        }
        a.pb(ans);
    }
    cout << a.size() << "\n";
    for(auto &i: a){
        for(auto &j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
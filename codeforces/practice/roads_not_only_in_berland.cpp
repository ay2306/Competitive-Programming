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
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> parent;
int fp(int x){
    if(x != parent[x])parent[x]=fp(parent[x]);
    return parent[x];
}
void un(int a,int b){
    parent[fp(a)] = fp(b);
}
V<PII> e;
int main(){
    int n;
    cin >> n;
    parent = V<int> (n+10);
    loop(i,0,n+10)parent[i]=i;
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        if(fp(a) == fp(b)){
            e.pb({a,b});
        }else un(a,b);
    }
    unordered_map<int,int> m;
    loop(i,1,n+1){
        m[fp(i)]++;
    }
    if(m.size() == 1){
        cout << 0;
        return 0;
    }
    stack<int> s;
    for(auto i: m)s.push(i.F);
    cout << s.size()-1 << "\n";
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        cout << e.back().F << " " << e.back().S << " " << a << " " << s.top() << "\n";
        e.pop_back();
    }
   return 0;
}
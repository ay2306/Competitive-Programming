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

bool comp(unordered_map<char,int> &f1, unordered_map<char,int> &f2){
    for(auto i: f1){
        if(i.second != f2[i.first])return false;
    }
    return (f1.size() == f2.size());
}

void solve(){
    string p,h;
    cin >> p >> h;
    unordered_map<char,int> f1,f2;
    for(auto i: p)f1[i]++;
    for(int i = 0; i < p.size() && i < h.size(); ++i)f2[h[i]]++;
    int i = p.size();
    do{
        if(comp(f1,f2)){
            cout << "YES\n";
            return;
        }
        f2[h[i-p.size()]]--;
        if(f2[h[i-p.size()]] == 0){
            f2.erase(h[i-p.size()]);
        }
        if(i < h.size()){
            f2[h[i]]++;
        }
        ++i;
    }while(i <= h.size());
    cout << "NO\n";
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}
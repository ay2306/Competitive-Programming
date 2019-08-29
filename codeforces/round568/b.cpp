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

void solve(){
    string a,b;
    cin >> a >> b;
    list<pair<char,int>> a1;
    list<pair<char,int>> a2;
    for(auto &i: a){
        if(a1.size() == 0)a1.pb(mp(i,1));
        else{
            if(a1.back().first == i){
                a1.rbegin()->second++;
            }else{
                a1.pb(mp(i,1));
            }
        }
    }
    for(auto &i: b){
        if(a2.size() == 0)a2.pb(mp(i,1));
        else{
            if(a2.back().first == i){
                a2.rbegin()->second++;
            }else{
                a2.pb(mp(i,1));
            }
        }
    }
    if(a1.size() != a2.size()){
        cout << "NO\n";
        return;
    }
    auto i1 = a1.begin();
    auto i2 = a2.begin();
    while(i1 != a1.end()){
        if(i1->first != i2->first){
            cout << "NO\n";
            return;
        }
        if(i1->second > i2->second){
            cout << "NO\n";
            return;
        }
        i1++;
        i2++;
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
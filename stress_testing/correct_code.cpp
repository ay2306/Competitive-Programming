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
#define FILE_READ_OUT freopen("correct_result.txt","w",stdout);
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
    unordered_map<char,int> m1,m2;
    // cout << "A = " << a << "\n";
    // cout << "B = " << b << "\n";
    loop(i,0,a.length()){
        m1[a[i]]++;
    }
    loop(i,0,b.length()){
        m2[b[i]]++;
    }
    string pref = "";
    string suff = "";
    bool special = true;
    loop(i,0,a.size()){
        if(a[i] != a[0]){
            special = (a[i] < a[0]);
            break;
        }
    }
    for(char i = 'a'; i <= 'z'; ++i){
        if(m1[i] > m2[i]){
            cout << "Impossible\n";
            return;
        }else{
            m2[i]-=m1[i];
        }
        if(i <= a.front() && !special){
            for(int j = 0; j < m2[i]; ++j){
                pref+=i;
            }
        }else if(i < a.front()){
            for(int j = 0; j < m2[i]; ++j){
                pref+=i;
            }
        }else{
            for(int j = 0; j < m2[i]; ++j){
                suff+=i;
            }
        }
    }
    cout << pref << a << suff << "\n";
}

int main(){
    FILE_READ_IN
    FILE_READ_OUT
    FAST
    int t = 0;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
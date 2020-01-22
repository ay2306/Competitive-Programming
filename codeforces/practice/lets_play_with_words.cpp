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
// * IMPORTANT: I forgot that the words should be unique
void solve(){
    int n;
    cin >> n;
    unordered_map<string,int> oc;
    unordered_map<string,int> oc1;
    unordered_map<string,int> cant_invert;
    unordered_map<string,V<int>> invert;
    V<int> ans;
    V<string> arr(n);
    loop(i,0,n)cin >> arr[i],oc[arr[i]]++;
    loop(i,0,n){
        reverse(all(arr[i]));
        string inv = arr[i];
        reverse(all(arr[i]));
        string k = "";
        k+=arr[i][0];
        k+=arr[i][arr[i].size()-1];
        oc1[k]++;
        if(oc.find(inv) != oc.end()){
            cant_invert[k]++;
        }else{
            invert[k].pb(i+1);
        }
    }
    if(oc1.find("00") != oc1.end() && oc1.find("11") != oc1.end() && oc1.size() == 2){
        cout << "-1\n";
        return;
    }
    string a,b;
    if(cant_invert["01"]+invert["01"].size() > cant_invert["10"] + invert["10"].size())a="01",b="10";
    else a = "10",b="01";
    while(invert[a].size() && int(invert[a].size()+cant_invert[a])-int(invert[b].size()+cant_invert[b]) > 1){
        invert[b].pb(invert[a].back());
        ans.pb(invert[a].back());
        invert[a].pop_back();
    }
    if(int(invert[a].size()+cant_invert[a])-int(invert[b].size()+cant_invert[b]) > 1){
        cout << "-1\n";
    }else{
        cout << ans.size() << "\n";
        for(auto i: ans)cout << i << " ";
        cout << "\n";
    }

}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        solve();
    }

   return 0;
}
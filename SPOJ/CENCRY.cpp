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
string cons = "";
string vow = "";
unordered_map<ll,ll> m;
bool isVowel(char a){
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

string solve(string &a){
    string ans = "";
    unordered_map<char,int> occ;
    for(auto &i: a){
        if(isVowel(i)){
            ll place = vow.size()*occ[i] + m[i]-1;
            ans+=(cons[place%cons.size()]);
        }else{
            ll place = cons.size()*occ[i] + m[i]-1;
            ans+=(vow[place%vow.size()]);
        }
        occ[i]++;
    }
    return ans;
}

int main(){
    for(char i = 'a'; i <= 'z'; ++i){
        if(isVowel(i)){
            vow+=i;
            m[i] = vow.size();
        }else{
            cons+=i;
            m[i] = cons.size();
        }
    }
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        cout << solve(a) << "\n";
    }
   return 0;
}
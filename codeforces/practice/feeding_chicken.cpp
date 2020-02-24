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
V<string> arr;
int n,m,k;

void dfs(int i, int j, char &a){
    if(i < 0 || j < 0 || i >= n || j >= m || arr[i][j] != '.')return;
    arr[i][j]=a;
    dfs(i-1,j,a);
    dfs(i+1,j,a);
    dfs(i,j-1,a);
    dfs(i,j+1,a);
}


void solve(){
    cin >> n >> m >> k;
    arr=V<string> (n);
    loop(i,0,n)cin >> arr[i];
    int cnt = 0;
    loop(i,0,n)loop(j,0,m)cnt+=arr[i][j]=='R';
    V<int> c(k);
    loop(i,0,cnt){
        c[i%k]++;
    }
    V<PII> pos;
    loop(i,0,n){
        if(i%2 == 0)loop(j,0,m)pos.emplace_back(i,j);
        else loopr(j,m-1,0)pos.emplace_back(i,j);
    }
    stack<char> op;
    for(char i = '0'; i <= '9'; ++i)op.push(i);
    for(char i = 'a'; i <= 'z'; ++i)op.push(i);
    for(char i = 'A'; i <= 'Z'; ++i)op.push(i);
    V<string> ans(n,string(m,'.'));
    int cur = 0;
    for(auto i: pos){
        if(arr[i.F][i.S]=='R'&&c[cur]==0)cur++,op.pop();
        if(arr[i.F][i.S]=='R')c[cur]--;
        ans[i.F][i.S]=op.top();
    }
    loop(i,0,n)cout << ans[i] << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}
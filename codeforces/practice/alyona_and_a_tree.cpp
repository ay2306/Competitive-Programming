#include <bits/stdc++.h>
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
#define pb emplace_back
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
const ll N = 2e5 + 10;
const ll inf = 1e9;
const double pi = acos(-1);
// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator>>(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
template<class T, class U>pair<T,U> operator+(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first+b.first,a.second+b.second);}
template<class T, class U>pair<T,U> operator-(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first-b.first,a.second-b.second);}
// Linear STL
// VECTOR
template<class T>istream& operator>>(istream& in, vector<T> &a){for(auto &i: a)cin >> i;return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a){for(auto &i: a)cout << i << " ";return out;}
// SET
template<class T>ostream& operator<<(ostream& out, const set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a){for(auto &i: a)cout << i << " ";return out;}
// MAP
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
int n, arr[N],dp[N][20],lev[N],diff[N];
ll dis[N][20];
V<int> g[N];

void compute_diff_array(int s = 1, int p = -1){
    for(int &i: g[s]){
        if(i == p)continue;
        compute_diff_array(i,s);
        diff[s]+=diff[i];
    }
}

void dfs(int s, int p = -1){
    for(auto &i: g[s]){
        lev[i] = lev[s]+1;
        dfs(i,s);
    }
}

void pre(){
    loop(j,1,20){
        loop(i,1,n+1){
            dp[i][j] = dp[dp[i][j-1]][j-1];
            dis[i][j] = dis[i][j-1] + dis[dp[i][j-1]][j-1];
        }
    }
}

void solve(int test_case){
    // Reading Input
    scanf("%d",&n);
    loop(i,1,n+1)scanf("%d",arr+i);
    loop(i,2,n+1){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].pb(i);
        dp[i][0] = a;
        dis[i][0] = b;
    }
    // Filling Data
    lev[1] = 1; 
    dfs(1);
    pre();
    loop(i,1,n+1){
        int node = i;
        int opt_lev = -1;
        int ans = -1;
        for(int lo = 1, hi = lev[node]; lo <= hi ;){
            int mi = lo + hi >> 1;
            int d = lev[node] - mi;
            ll sum = 0;
            loop(j,0,20){
                if((d>>j)&1){
                    sum+=dis[node][j];
                    node = dp[node][j];
                }
            }
            node = i;
            if(sum <= arr[node]){
                ans = mi;
                hi = mi - 1;
            }else{
                lo = mi + 1;
            }
        }
        if(ans == -1 || ans == lev[node])continue;
        int d = lev[node] - ans;
        loop(j,0,20){
            if((d>>j)&1){
                node = dp[node][j];
            }
        }
        diff[dp[node][0]]--;
        diff[dp[i][0]]++;
    }
    compute_diff_array();
    loop(i,1,n+1)printf("%d ",diff[i]);
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}

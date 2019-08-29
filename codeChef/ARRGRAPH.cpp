/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

std::map<pair<int,int>,int> co_primes;
std::vector<vector<int> > adj;
std::vector<bool> visited;


// void addEdge(int a, int b){
//     adj[a].pb(b);
//     adj[b].pb(a);
// }

int dfs(int s){
    int ans = 1;
    visited[s] = true;
    for(auto i: adj[s]){
        if(!visited[i])ans+=dfs(i);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    adj = vector<vector<int> > (n, vector<int> ());
    visited = vector<bool> (n,false);
    vector<int> arr(n,0);
    loop(i,0,n)cin >> arr[i];
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; j++){
            if(co_primes.find(mp(arr[i],arr[j])) != co_primes.end()){
                // addEgde(i,j);
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    int k = dfs(0);
    if(k == n){
        cout << "0\n";
        for(auto i: arr){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if(arr[0] == 29)arr[0]=43;
    else arr[0] = 29;
    cout << "1\n";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
    
}

int main(){
    for(int i = 2; i <= 50; ++i){
        for(int j = i+1; j <= 50; ++j){
            if(__gcd(i,j) == 1){
                co_primes[mp(i,j)]++;
                co_primes[mp(j,i)]++;
            }
        }
    }
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
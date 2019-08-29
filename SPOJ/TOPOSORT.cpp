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
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> reStack;
vector<int> inDegree;

bool dfsCycle(int s){
    if(!visited[s]){
        visited[s] = true;
        reStack[s] = true;
        bool ans = true;
        for(auto i: adj[s]){
            if(!visited[i] && dfsCycle(i)){
                // cout << "CYCLE DETECTED\n";
                return true;
            }else if(reStack[i]){
                // cout << "CYCLE DETECTED\n";
                return true;
            }
        }
    }
    reStack[s] = false;
    return false;;
}

int main(){
    int n,m;
    cin >> n >> m;
    adj = vector<vector<int> > (n,vector<int> ());
    visited = vector<bool> (n,false);
    reStack = vector<bool> (n,false);
    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            if(dfsCycle(i)){
                cout << "Sandro fails.";
                return 0;
            }
        }
    }
    visited = vector<bool> (n,false);
    inDegree = vector<int> (n,0);
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < n; ++i){
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    for(int i = 0; i < n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.pb(q.top());
        int j = q.top();
        q.pop();
        for(auto i: adj[j]){
            if(!visited[i]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i])ans.pb(i);
    }
    for(auto i: ans){
        cout << i+1 << " ";
    }
    return 0;
}
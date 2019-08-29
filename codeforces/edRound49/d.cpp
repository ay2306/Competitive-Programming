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
V<int> v;
V<int> *adj;
int *visited;
int mn;

void BFS(int s){
    list<int> queue;
    visited[s] = 1;
    queue.push_back(s);
    // list<int>::iterator itr;
    while(!queue.empty()){
        s = queue.front();
        mn = min(v[s],mn);
        cout << mn << "\n";
        queue.pop_front();
        for(V<int>::IT itr = adj[s].begin(); itr != adj[s].end(); ++itr){
            if(!visited[*itr]){
                visited[*itr]=1;
                queue.push_back(*itr);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj = new V<int>[n];
    visited = (int*)calloc(n+1,sizeof(int));
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        v.pb(a);
    }
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        a--;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        mn = INT_MAX;
        if(!visited[i])
        {   
            BFS(i);
            ans+=mn;
        }
    }
    cout << ans;
    return 0;

}
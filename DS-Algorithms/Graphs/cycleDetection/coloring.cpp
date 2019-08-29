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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;
V<V<int> > adj;
int n,m;

bool dfs(int s,V<int> visited){
    visited[s] = 1;
    for(auto i: adj[s]){
        if(visited[i] == 1)return true;
        if(visited[i] == 0 && dfs(i,visited))return true;
    }
    visited[s] = 2;
    return false;
}


bool isCyclic(){
    V<int> visited (n,0);
    loop(i,0,n){
        if(visited[i] == 0 && dfs(i,visited))return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    adj = V<V<int> > (n);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);    
        adj[b-1].pb(a-1);    
    }
    if(isCyclic()){
        printf("YES it is cyclic\n");
    }else{
        printf("Not Cyclic");
    }
    return 0;
}
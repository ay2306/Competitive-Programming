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
#define PIIL pair<long long int, pair<int,int> >
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

vector<int> parent;
vector<int> Rank;

int findParent(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[parent[x]]];
        x = parent[x];
    }
    return x;
}

void UNION(int x,int y){
    int px = findParent(x);
    int py = findParent(y);
    if(Rank[px] > Rank[py]){
        parent[py] = px;
    }
    else if(Rank[px] < Rank[py]){
        parent[px] = py;
    }else{
        parent[py] = px;
        Rank[px]++;
    }
}

void solve(){
    int n;
    cin >> n;
    parent = vector<int> (n,0);
    Rank = vector<int> (n,0);
    priority_queue<PIIL, vector<PIIL>, greater<PIIL> > q;
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        string a;
        cin >> a;
        int k;
        cin >> k;
        while(k--){
            int x;
            ll y;
            cin >> x >> y;
            q.push(mp(y,mp(i,x-1)));   
        }
    }
    ll ans = 0;
    while(q.size()){
            // cout << "jjj\n";
        PIIL p = q.top();
        q.pop();
        if(findParent(p.second.first) != findParent(p.second.second)){
            UNION(p.second.second,p.second.first);
            ans+=p.first;
        }
    }
    cout << ans << "\n";
}

int main(){
    // FILE_READ
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
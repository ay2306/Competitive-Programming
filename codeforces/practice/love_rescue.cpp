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
V<int> Rank;
V<int> parent;

int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void UNION(int a, int b){
    int pa = findParent(a);
    int pb = findParent(b);
    if(Rank[pa] >= Rank[pb]){
        parent[pb] = pa;
        Rank[pa] += ((Rank[pa] == Rank[pb])?1:0);
    }else{
        parent[pa] = pb;
    }
}

int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    Rank = V<int>(26,0);
    parent = V<int>(26,0);
    loop(i,1,26)parent[i] = i;
    V<PII> ans;
    for(int i = 0; i < n; ++i){
        int e = a[i] - 'a';
        int f = b[i] - 'a';
        int ep = findParent(e);
        int ef = findParent(f);
        if(ep == ef)continue;
        else{
            UNION(ep,ef);
            ans.pb(mp(e,f));
        }
    }
    cout << ans.size() << "\n";
    for(auto i: ans){
        cout << char(i.F+'a') << " " << char(i.S+'a') << "\n";
    }
    return 0;
}
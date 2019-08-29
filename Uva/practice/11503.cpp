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
#define MAXN 1001000
using namespace std;

class solution{
vector<int> parent;
vector<int> Rank;
vector<int> sz;
public:
    solution(){
        int n;
        int q,cnt = 0;
        cin >> n;
        unordered_map<string,int> m;
        vector<pair<string,string> > arr;
        while(n--){
            string a,b;
            cin >> a >> b;
            if(m.find(a) == m.end())m[a] = cnt++;
            if(m.find(b) == m.end())m[b] = cnt++;
            arr.pb(mp(a,b));
        }
        parent = vector<int> (m.size(),0);
        Rank = vector<int> (m.size(),0);
        sz = vector<int> (m.size(),1);
        for(int i = 0; i < m.size(); ++i)parent[i] = i;
        for(auto i: arr){
            string a = i.first;
            string b = i.second;
            int pa = findParent(m[a]);
            int pb = findParent(m[b]);
            if(pa != pb){
                UNION(pa,pb);
            }
            cout << sz[findParent(m[a])] << "\n";
        }
    }
    void UNION(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if(Rank[px] > Rank[py]){
            parent[py] = parent[px];
            sz[px]+=sz[py];
        }
        else if(Rank[px] < Rank[py]){
            parent[px] = parent[py];
            sz[py]+=sz[px];
        }
        else if(Rank[px] == Rank[py]){
            parent[py] = parent[px];
            sz[px]+=sz[py];
        }
    }
    int findParent(int x){
        while(parent[x] != x)x = parent[x];
        return x;
    }

};
int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--){
        solution(s);
    }
    return 0;
}
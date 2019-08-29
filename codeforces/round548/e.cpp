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

class comp{
public:
    bool operator() (PII a, PII b){
        if(a.F < b.F)return false;
        return true;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<PII,V<PII>,comp> p[m];
    V<int> skill(n);
    loop(i,0,n)cin >> skill[i];
    V<int> club(n);
    loop(i,0,n){
        cin >> club[i];
        club[i]--;
        p[club[i]].push(mp(skill[i],i));
    }
    V<bool> active(n,true);
    int t;
    cin >> t;
    V<int> ans(t);
    for(int i = 0; i < m; ++i){
        printf("Size of club %d = %d\n",i,p[i].size());
    }
    for(int rajma = 0; rajma < t; ++rajma){
        int a;
        cin >> a;
        a--;
        int c = club[a];
        active[a] = false;
        while(p[c].size() && !active[p[c].top().second])p[c].pop();
        set<int> cs;
        for(int i = 0; i < m; ++i){
            if(p[i].size() == 0)continue;
            cs.insert(skill[p[i].top().second]);
        }
        // cout << "On day " << rajma << ": \n" ;
        // for(auto k: cs){
        //     cout << k << " ";
        // }
        // for(int i = 0; i < m; ++i){
        cout << "\n";
        for(int i = 0; i < 5001; ++i){
            if(!binary_search(cs.begin(),cs.end(),i)){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
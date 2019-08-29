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

void solve(){
    int n,m;
    cin >> n >> m;
    V<V<char> > R,G;
    for(int i = 0; i < n; ++i){
        V<char> t;
        if(R.size() == 0)t.pb('R');
        else t.pb(((R[i-1][0] == 'R')?'G':'R'));
        for(int j = 1; j < m; ++j){
            t.pb(((t[j-1] == 'R')?'G':'R'));
        }
        R.pb(t);
    }
    for(int i = 0; i < n; ++i){
        V<char> t;
        if(G.size() == 0)t.pb('G');
        else t.pb(((G[i-1][0] == 'R')?'G':'R'));
        for(int j = 1; j < m; ++j){
            t.pb(((t[j-1] == 'R')?'G':'R'));
        }
        G.pb(t);
    }
    // for(auto i: R){
    //     for(auto j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // for(auto i: G){
    //     for(auto j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    int costR = 0; 
    int costG = 0; 
    for(int i = 0; i < n; ++i){
        V<char> t;
        for(int j = 0; j < m; ++j){
            char a;
            cin >> a;
            if(a != R[i][j]){
                if(R[i][j] == 'R')costR+=5;
                else costR+=3;
            }
            if(a != G[i][j]){
                if(G[i][j] == 'R')costG+=5;
                else costG+=3;
            }
        }
    }
    cout << min(costR,costG) << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
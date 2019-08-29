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
int C;
int n;
bool mat[103][103];
bool vis[103];

void printLN(){
    cout << "+";
    for(int i = 0; i < n*2 - 1; ++i)cout << "-";
    cout << "+\n";
}

void dfs(int at, int absent){
    if(at == absent)return;
    vis[at] = true;
    for(int i = 0; i < n; ++i){
        if(mat[at][i] && !vis[i])dfs(i,absent);
    }
}

void solve(){
    cin >> n;
    init(mat,false);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mat[i][j];
        }
    }
    bool output[103][103];
    bool firstVis[103];
    init(vis,false);
    dfs(0,-1);
    loop(i,0,103)firstVis[i] = vis[i];
    for(int i = 0; i < n; ++i){
        init(vis,false);
        dfs(0,i);
        for(int j = 0; j < n; ++j){
            if(firstVis[j] && ! vis[j])output[i][j] = true;
            else output[i][j] = false;
        }
        output[i][i] = firstVis[i];
    }
    cout << "Case " << C++ << ":\n";
    printLN();
    for(int i = 0; i < n; ++i){
        cout << "|";
        for(int j = 0; j < n; ++j){
            if(output[i][j]) cout << "Y|";
            else cout << "N|";
        }
        cout << "\n";
        printLN();
    }

}

int main(){
    // FILE_READ
    C = 1;
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
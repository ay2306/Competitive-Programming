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
#define MAXN 110
using namespace std;
int n,m;
V<int> g[MAXN];

bool comp(int a, int b){
    if(g[a].size() <= g[b].size())return true;
    return false;
}

bool isEnemy(vector<int> v, int a){
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < g[v[i]].size(); ++j){
            if(g[v[i]][j] == 0)return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;  
    V<int> teamA, teamB;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)arr[i]=i;
    // loop(i,0,n)cout << arr[i] << " ";
    // cout << endl;
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    sort(arr,arr+n,comp);
    int j = 1;
    int ans =0;
    for(int i = 0; i < n; ++i){
        if(!isEnemy(teamA,arr[i])){
            teamA.pb(arr[i]);
            ++j;
            continue;
        }
        else if(!isEnemy(teamB,arr[i])){
            teamB.pb(arr[i]);
            ++j;
            continue;
        }else{
            ans++;
        }
    }
    // for(int i = 0; i < teamA.size(); ++i)cout << teamA[i] << " ";
    // cout << endl;
    // for(int i = 0; i < teamB.size(); ++i)cout << teamB[i] << " ";
    // cout << endl;
    if((n-ans)%2 == 1)ans++;
    cout << ans;
    return 0;
}
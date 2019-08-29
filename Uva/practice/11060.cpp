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

int cases = 1;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> inDegree;

int main(){
    // FILE_READ
    int n;
    cin >> n;
    while(1){
        adj = vector<vector<int> > (n, vector<int> ());
        visited = vector<bool> (n,false);
        inDegree = vector<int> (n,0);
        unordered_map<string,int> m1;
        unordered_map<int,string> m2;
        int cnt = 0;
        loop(i,0,n){
            string a;
            cin >> a;
            m1[a] = cnt;
            m2[cnt++] = a;
        }

        int m;
        cin >> m;
        while(m--){
            string a,b;
            cin >> a >> b;
            adj[m1[a]].pb(m1[b]);
        }
        for(int i = 0; i < n; ++i){
            for(auto k: adj[i])inDegree[k]++;
        }
        priority_queue<string,vector<string>,greater<string> > q;
        for(int i = 0; i < n; ++i){
            if(inDegree[i] == 0){
                q.push(m2[i]);
                visited[i] = true;
            }
        }
        vector<string> ans;
        while(q.size()){
            ans.pb(q.top());
            int u = m1[q.top()];
            q.pop();
            for(auto i: adj[u]){
                if(!visited[i]){
                    inDegree[i]--;
                    if(inDegree[i] == 0){
                        visited[i] = true;
                        q.push(m2[i]);
                    }
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",cases++);
        for(int i = 0; i < ans.size(); ++i){
            // cout << m2[ans[i]];
            cout << ans[i];
            if(i+1 == ans.size())cout << ".";
            else cout << " ";
        }
        cout << "\n\n";
        if(cin >> n){

        }else{
            break;
        }
    }
    return 0;
}
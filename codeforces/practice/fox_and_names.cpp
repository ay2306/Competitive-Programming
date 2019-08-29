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
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> reStack;
vector<string> arr;
vector<int> inDegree;

bool dfsCycle(int s){
    if(!visited[s]){
        visited[s] = true;
        reStack[s] = true;
        bool ans = true;
        for(auto i: adj[s]){
            if(!visited[i] && dfsCycle(i)){
                // cout << "CYCLE DETECTED\n";
                return true;
            }else if(reStack[i]){
                // cout << "CYCLE DETECTED\n";
                return true;
            }
        }
    }
    reStack[s] = false;
    return false;;
}

int main(){
    int n;
    cin >> n;
    unordered_map<char,int> m;
    int nodes = 0;
    adj = vector<vector<int> > (26,vector<int> ());
    arr = vector<string> (n);
    visited = vector<bool> (26,false);
    reStack = vector<bool> (26,false);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i < n; ++i){
        int found_diff = 0;
        for(int j = 0; j < arr[i].size() && j < arr[i-1].size(); ++j){
            if(arr[i-1][j] != arr[i][j]){
                found_diff++;
                // printf("Edge from %c to %c\n",arr[i-1][j],arr[i][j]);
                adj[arr[i-1][j]-'a'].pb(arr[i][j]-'a');
                break;
            }
        }
        if(!found_diff && arr[i-1].size() > arr[i].size()){
            cout << "Impossible\n";
            return 0;
        }
    }
    for(int i = 0; i < 26; ++i){
        if(!visited[i]){
            if(dfsCycle(i)){
                cout << "Impossible";
                return 0;
            }
        }
    }
    visited = vector<bool> (26,false);
    inDegree = vector<int> (26,0);
    queue<int> q;
    for(int i = 0; i < 26; ++i){
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    for(int i = 0; i < 26; ++i){
        if(inDegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    vector<char> ans;
    while(!q.empty()){
        ans.pb(char(q.front()+'a'));
        int j = q.front();
        q.pop();
        for(auto i: adj[j]){
            if(!visited[i]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    for(int i = 0; i < 26; ++i){
        if(!visited[i])ans.pb(char(i+'a'));
    }
    for(auto i: ans){
        cout << i;
    }
    return 0;
}
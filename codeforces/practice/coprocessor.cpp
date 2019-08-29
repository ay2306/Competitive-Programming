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
V<int> in;
int n,m;
V<int> arr;    
int calls = 0;

set<int> main_tasks,co_tasks;
void clear_task(int s){
    for(auto i: adj[s]){
        in[i]--;
        if(in[i] == 0){
            if(arr[i])co_tasks.insert(i);
            else main_tasks.insert(i);
        }
    }
}

int main(){
    cin >> n >> m;
    adj = V<V<int> > (n,V<int> ());
    arr = V<int> (n,0);
    in = V<int> (n,0);
    loop(i,0,n)cin >> arr[i];
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        in[b]++;
        adj[a].pb(b);
    }
    for(int i = 0; i < n; ++i){
        if(in[i] == 0){
            if(arr[i])co_tasks.insert(i);
            else main_tasks.insert(i);
        }
    }   
    while(main_tasks.size() || co_tasks.size()){
        if(main_tasks.size() == 0){
            calls++;
            while(co_tasks.size()){
                int u = *co_tasks.begin();
                co_tasks.erase(co_tasks.begin());
                clear_task(u);
            }
        }else{
            while(main_tasks.size()){
                int u = *main_tasks.begin();
                main_tasks.erase(main_tasks.begin());
                clear_task(u);
            }
        }
    }
    cout << calls ;
    return 0;
}
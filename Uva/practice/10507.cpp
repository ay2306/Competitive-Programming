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

int main(){
    // FILE_READ
    int n,q;
    std::cin >> n;
    while(1){
        vector<vector<int> > adj(n,vector<int> ());
        unordered_map<char,int> active;
        vector<char> act;
        unordered_map<char,int> node;
        unordered_map<int,char> nodeC;
        cin >> q;
        string a;
        cin >> a;
        int cnt = 0;
        for(auto i: a){
            active[i] = 1;
            act.pb(i);
            if(node.find(i) == node.end()){
                node[i] = cnt++;
                nodeC[cnt-1] = i;
            }
        }
        while(q--){
            cin >> a;
            if(node.find(a[0]) == node.end()){
                node[a[0]] = cnt++;
                nodeC[cnt-1] = a[0];
            }
            if(node.find(a[1]) == node.end()){
                node[a[1]] = cnt++;
                nodeC[cnt-1] = a[1];
            }
            int fn = node[a[0]];
            int sn = node[a[1]];
            adj[fn].pb(sn);
            adj[sn].pb(fn);
        }
        int ans = 0;
        int prv = act.size();
        if(prv != n){
            do{ 
                // for(auto i : act){
                //     cout << i << " ";
                // }
                // cout << "\n";
                prv = act.size();
                vector<char> tmp;
                for(auto i : node){
                    int c = 0;
                    if(active.find(i.first) != active.end())continue;
                    // cout << i.first << " ";
                    for(auto k: adj[i.second]){
                        // cout << k << " ";
                        if(active.find(nodeC[k]) != active.end())c++;
                        // c+=active[k];
                    }
                    // cout << "\n";
                    if(c >= 3){
                        tmp.pb(i.first);
                    }
                }
                for(auto i : tmp){
                    act.pb(i);
                    active[i] = 1;
                }
                ans++;
                if(act.size() == n)break;
            }while(prv != act.size());
            // cout << endl;
        }
        if(act.size() == n){
            cout << "WAKE UP IN, "<< ans << ", YEARS\n" ;
        }else{
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
        if(cin >> n){}
        else{
            break;
        }
    }
    return 0;
}
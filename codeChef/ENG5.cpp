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
#define MAXN 25
using namespace std;

set<int> s;
unordered_map<int,V<int> > in;

int main(){
    int n,m;
    cin >> n >> m;
    V<int> arr(n);
    loop(i,0,n){
        cin >> arr[i];
        if(in.find(arr[i])==in.end())in[arr[i]] = V<int> ();
        in[arr[i]].pb(i);
    }
    int ans = 0;
    int fi = 0;
    for(int j = 0; j < m; ++j){
        int mn = n+1;
        int id = 0;
        for(auto i: in){
            int c = 0;
            V<int> a = in[i.first];
            int li = fi+a.size()-1;
            for(auto k: a){
                if(k < fi || k > li){
                    c++;
                }
            }
            if(c <= mn){
                id = i.first;
                mn = c;
            }
        }
        // cout << id << " " << mn << "\n";
        ans+=mn;
        fi += in[id].size();
        in.erase(id);
    }
    cout << ans;
    return 0;
}
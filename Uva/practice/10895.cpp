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

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int>b){
    if(a.first.first < b.first.first)return true;
    if(a.first.first > b.first.first)return false;
    if(a.first.second > b.first.second)return false;
    return false;
}

int main(){
    // FILE_READ
    int n,m;
    cin >> n >> m;
    while(1){
        vector<pair<pair<int,int>,int> > arr;
        V<V<PII>> row(m+1,V<PII>());
        for(int i = 1; i <= n; ++i){
            int k;
            vector<int> col;
            cin >> k;
            for(int j = 0; j < k; ++j){
                int a;
                cin >> a;
                col.pb(a);
            }
            for(auto j: col){
                int a;
                cin >> a;
                arr.pb(mp(mp(j,i),a));
                row[j].pb(mp(i,a));
            }
        }
        cout << m << " " << n << "\n";
        for(int i = 1; i <= m; ++i){
            cout << row[i].size();
            if(row[i].size() != 0)cout << " ";
            for(int j = 0; j < row[i].size(); ++j){
                cout << row[i][j].first;
                if(j+1 != row[i].size())cout << " ";
            }
            cout << "\n";
            for(int j = 0; j < row[i].size(); ++j){
                cout << row[i][j].second;
                if(j+1 != row[i].size())cout << " ";
            }
            cout << "\n";
        }
        if(cin >> n >> m){
            // cout << "\n";
        }
        else break;
    }   
    return 0;
}
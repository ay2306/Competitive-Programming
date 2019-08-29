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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> v;
    for(int i =0; i < n; ++i){
        string s;
        cin >> s;
        v.pb(s);
    }   
    V<int> r,c;
    for(int i = 0; i < n; ++i){
        bool pos = true;
        for(int j = 0; j < m; ++j){
            if(v[i][j] == 'S')pos=false;
        }
        if(pos)r.pb(i);
    }
    for(int i = 0; i < m; ++i){
        bool pos = true;
        for(int j = 0; j < n; ++j){
            if(v[j][i] == 'S')pos=false;
        }
        if(pos)c.pb(i);
    }
    int co = 0;
    for(int k = 0; k < r.size(); ++k){
        int i = r[k];
        for(int j = 0; j < m; ++j){
            // cout << "i = "  << i << "  j = " << j << endl;
            if(v[i][j]!='e')co++;
            v[i][j] = 'e';
        }
    }
    for(int k = 0; k < c.size(); ++k){
        int i = c[k];
        for(int j = 0; j < n; ++j){
            // cout << "i = "  << i << "  j = " << j << endl;
            if(v[j][i]!='e')co++;
            v[j][i] = 'e';
        }
    }
    cout << co;
    return 0;
}
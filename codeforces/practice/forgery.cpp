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
int n,m;

bool Check(V<string> arr, int i, int j, string t){
    int ci,cj;
    if(t == "UL"){
        ci = 0;
        cj = 0;
    }
    if(t == "UM"){
        ci = 1;
        cj = 0;
    }
    if(t == "UR"){
        ci = 2;
        cj = 0;
    }
    if(t == "ML"){
        ci = 0;
        cj = 1;
    }
    if(t == "MM"){
        ci = 1;
        cj = 1;
    }
    if(t == "MR"){
        ci = 2;
        cj = 1;
    }
    if(t == "LL"){
        ci = 0;
        cj = 2;
    }
    if(t == "LM"){
        ci = 1;
        cj = 2;
    }
    if(t == "LR"){
        ci = 2;
        cj = 2;
    }
    PII pos[7] = {mp(1,0),mp(2,0),mp(0,1),mp(0,2),mp(2,1),mp(2,2),mp(1,2)};
    for(int k = 0; k < 7; ++k){
        if(i+pos[k].first-ci >= 0 && i+pos[k].first-ci < n && j+pos[k].second-cj >= 0 && j+pos[k].second-cj < m){
            if(arr[i+pos[k].first-ci][j+pos[k].second-cj] != '#')return false;
        }
    }
    return true;
}


int main(){
    cin >> n >> m;
    V<string> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    V<string> all;
    all.pb("UL");
    all.pb("ML");
    all.pb("LL");
    all.pb("UM");
    all.pb("MM");
    all.pb("LM");
    all.pb("UR");
    all.pb("MR");
    all.pb("LR");
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            bool pos = false;
            if(arr[i][j] == '#'){
                for(int k = 0; k < all.size(); ++k){
                    pos = (pos || Check(arr,i,j,all[k]));
                }
            }
            if(!pos){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
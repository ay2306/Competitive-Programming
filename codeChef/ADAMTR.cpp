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

void solve(){
    int n;
    bool pos = true;
    cin >> n;
    V<V<int> > a(n,V<int>(n,0));
    V<V<int> > b(n,V<int>(n,0));
    V<int> change(n,-1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)cin >> a[i][j];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)cin >> b[i][j];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == b[i][j] && a[j][i] == b[j][i]){
                // if(change[i] == 1 || change[j] == 1){
                //     pos = false;
                // }else{
                //     change[i] = 0;
                //     change[j] = 0;
                // }
                continue;
            }
            else if(a[i][j] == b[j][i] && a[j][i] == b[i][j]){
                // if(change[i] == 0 || change[j] == 0){
                //     pos = false;
                // }else{
                //     change[i] = 0;
                //     change[j] = 0;
                // }
                continue;
            }
            // printf("FALSE AT (%d, %d)\n",i,j);
            pos = false;
        }
    }

    if(pos)cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    FILE_READ_IN
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
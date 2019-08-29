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
    ll seq = 1;
    while(1){
        int n,m,c;
        cin >> n >> m >> c;
        if(n == 0 || m == 0 || c == 0)break;
        // if(seq != 1)cout << "\n";
        ll *power = new ll[n+1];
        int *state = (int*)calloc(n+1,sizeof(int));
        for(int i = 1; i <= n; ++i)cin >> power[i];
        ll maxPower = 0;
        ll currentPower = 0;
        for(int i = 0; i < m; ++i){
            int a;
            cin >> a;
            state[a]^=1;
            if(state[a]){
                currentPower += power[a];
            }else{
                currentPower -= power[a];
            }
            maxPower = max(currentPower,maxPower);
        }
        cout << "Sequence " << seq++ << "\n";
        if(maxPower > c){
            cout << "Fuse was blown.\n";
        }else{
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << maxPower << " amperes.\n";
        }
        cout << "\n";
    }
    return 0;
}
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
    int a1,a2,a4,a3;
    while(scanf("%d%d%d%d",&a1,&a2,&a3,&a4)!=EOF){
        ll a,b,c,d;
        a = a1;
        b = a2;
        c = a3;
        d = a4;
        // cin >> a >> b >> c >> d;
        if(a == 0 || b == 0 || c == 0 || d == 0)break;
        ll minCost = LONG_LONG_MAX;
        for(int i = 0; i < c ;++i){
            ll e,f;
            cin >> e;
            for(int j = 0; j < d; ++j){
                cin >> f;
                if(f >= a)minCost = min(a*e,minCost);
            }
        }
        if(minCost > b)cout << "stay home\n";
        else cout << minCost << "\n";
    }
    return 0;
}
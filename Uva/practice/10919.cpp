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
    while(1){
        int n,m;
        bool pos = true;
        cin >> n;
        if(n == 0)break;
        cin >> m;
        unordered_map<string,int> MAP;
        for(int i = 0; i < n; ++i){
            string a;
            cin >> a;
            MAP[a] = 1;
        }
        for(int i = 0; i < m; ++i){
            int cnt = 0;
            int mxi,mn;
            cin >> mxi >> mn;;
            for(int j = 0; j < mxi; ++j){
                string a;
                cin >> a;
                if(MAP.find(a) != MAP.end())cnt++;
            }
            if(cnt < mn)pos = false;
        }
        if(pos)cout << "yes\n";
        if(!pos)cout << "no\n";
    }
    return 0;
}
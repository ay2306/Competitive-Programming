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
    int n,m;
    cin >> n >> m;
    while(1){
        unordered_map<int,V<int> > arr;
        for(int i = 1; i <= n; ++i){
            int a;
            cin >> a;
            if(arr.find(a) == arr.end()){
                arr[a] = vector<int>();
            }
            arr[a].pb(i);
        }
        while(m--){
            int a,b;
            cin >> b >> a;
            auto k = arr.find(a);

            if(k == arr.end()){
                cout << "0\n";
            }else{
                if(arr[a].size() < b){
                    cout << "0\n";
                }else{
                    cout << arr[a][b-1] << "\n"; 
                }
            }
        }
        if(cin >> n >> m){

        }else{
            break;
        }
    }
    return 0;
}
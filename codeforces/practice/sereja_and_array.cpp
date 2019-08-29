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
    ull n,m,y_sum = 0;
    cin >> n >> m;
    ull *arr = new ull[n+1];
    for(ull i = 1; i < n+1; ++i)cin >> arr[i];
    while(m--){
        ull t,a,b;
        cin >> t;
        if(t == 1){
            cin >> a >> b;
            arr[a] = b-y_sum;
        }
        if(t == 2){
            cin >> a;
            y_sum+=a;
        }
        if(t == 3){
            cin >> a;
            cout << arr[a]+y_sum << endl;
        }
    }   
    return 0;
}
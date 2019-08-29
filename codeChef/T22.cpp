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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    int v[1000] = {0};
    for(int i = 2; i < 1000; ++i)if(v[i] == 0)for(int j = 2; i*j < 1000; ++j)v[i*j]=1;
    int t;
    cin >> t;
    while(t--){
        int a,n;
        cin >> n;
        int sm = INT_MAX;
        bool one_crit = false;
        while(n--){
            cin >> a;
            if(a == 1)one_crit = true;
            else if(v[a] == 0){
                if(a < sm)sm=a;
            }
        }
        if(sm!=INT_MAX && one_crit){
            cout << sm << endl;
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}
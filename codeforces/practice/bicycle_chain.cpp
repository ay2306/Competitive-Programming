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
    int n,*a,m,*b;
    cin >> n;
    b = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    cin >> m;
    a = new int[m];
    for(int i = 0; i < m; ++i)cin>>a[i];
    int mx = 0;
    int mc = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i]%b[j] == 0){
                int t = a[i]/b[j];
                if(t == mx)mc++;
                if(t>mx){
                    mx = t;
                    mc = 1;
                }
            }
        }
    }
    cout << mc;
    return 0;
}
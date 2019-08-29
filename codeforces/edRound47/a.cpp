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
    // freopen("input.txt","r",stdin);
    int co=0,n,m;
    cin >> n >> m;
    int *c = new int[n];
    int *a = new int[m];
    for(int i = 0; i < n; ++i)cin >> c[i];
    for(int i = 0; i < m; ++i)cin >> a[i];
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(c[i] <= a[j]){
            ++j;
            ++co;
        }
        ++i;
        if(j == m || i == n)break;
    }
    cout << co;
    return 0;
}
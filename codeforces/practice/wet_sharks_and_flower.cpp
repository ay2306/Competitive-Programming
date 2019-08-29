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
using namespace std;


const ll maxn = 1e5;

int main(){
    ll n,p;
    cin >> n >> p;
    V<double> r(n);
    V<double> l(n);
    loop(i,0,n)cin >> l[i] >> r[i];
    double ans = 0;
    for(int i = 0; i+1 < n; ++i){
        double a1 = long(r[i]/p) - long((l[i]-1)/p);
        a1 = r[i] - l[i] + 1 - a1;
        a1/=(r[i]-l[i] + 1);
        double a2 = long(r[i+1]/p) - long((l[i+1]-1)/p);
        a2 = r[i+1] - l[i+1] + 1 - a2;
        a2/=(r[i+1]-l[i+1] + 1);
        ans+=(1-(a1*a2));
    }
    double a1 = long(r[0]/p) - long((l[0]-1)/p);
    a1 = r[0] - l[0] + 1 - a1;
    a1/=(r[0]-l[0] + 1);
    double a2 = long(r[n-1]/p) - long((l[n-1]-1)/p);
    a2 = r[n-1] - l[n-1] + 1 - a2;
    a2/=(r[n-1]-l[n-1] + 1);
    ans+=(1-(a1*a2));
    printf("%.10f",ans*2000);
    return 0;
}
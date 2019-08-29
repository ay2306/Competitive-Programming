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
    FAST
    // FILE_READ_IN
    const double pi = acos(-1);
    int n;
    double mx = 0.0;
    double mx2 = 0.0;
    double mn = 2*pi;
    cin >> n;
    V<double> arr(n);
    loop(i,0,n){
        double a,b;
        cin >> a >> b;
        arr[i] = atan2(b,a)*180/pi;
    }
    sort(arr.begin(),arr.end());
    double ans = 1e9;
    loop(i,0,n-1){
        ans = min(ans,360-(arr[i+1]-arr[i]));
    }
    // for(auto i: arr)cout << i << " ";
    // cout << endl;
    ans = min(ans,(arr[n-1]-arr[0]));
    printf("%.10f",ans);
    return 0;

}
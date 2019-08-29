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
#define MAXN 25
using namespace std;

double ans = 0;
V<ll> arr;
V<double> p;
const ll inf = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    arr = V<ll> (n,0);
    p = V<double> (n);
    loop(i,0,n)cin >> arr[i];
    loop(i,0,n)cin >> p[i];
    double ans = 0;
    loop(i,0,30){
        double prob = 0;
        //prob  = bit was set before
        loop(j,0,n){
            if(arr[j] & (1LL << i)){
                //if(bit was set before) then probablity it is set now = prob * (1-p[j])
                //if(bit was not set before) then probability it is set now = (1-prob) * p[j];
                prob = prob*(1-p[j]) + (1-prob)*p[j];
            }
        }
        ans += (prob * (1LL << i));
    }
    printf("%.10f\n",ans);
}

int main(){
    // FILE_READ_OUT
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
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
#define MAXN 25
using namespace std;
const double pi  =3.141592653589793238463;

double lnfact(double n)
{
    double ans =  n * log(n);
    ans = ans - n;
    ans = ans + (0.5 * log(pi*2*n));
    return ans;
}
bool check(double n,double a){
    // cout << n <<  " ";
    double k = lnfact(n);
    k = k/log(a);
    // cout << k << "\n";
    if (k > n){
        return true;
    }
    return false;
}


void solve(){
    double a;
    // scanf("%d",&a);
    cin >> a;
    double low = 0;
    double high = 1000000000000000000;
    ll ans = high;
    while (low <= high){
        // cout << mid;
        ll mid = ((low+high)/2);
        // cout << low << " " << high << endl;
        if(check(double(mid),a)){
            ans = min(mid,ans);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    int t = 1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
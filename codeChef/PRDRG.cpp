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
PLL l,r;

PLL mid(PLL a, PLL b){
    PLL ans;
    ans.second = a.second*b.second;
    ans.first = a.second*b.first + a.first*b.second;
    ans.second*=2;
    int k = __gcd(ans.first,ans.second);
    ans.first = ans.first/k;
    ans.second = ans.second/k;
    return ans;
}

void solve(){
    int n;
    l = mp(0*1LL,1*1LL);
    cin >> n;
    r = mp(1*1LL,1*1LL);
    int c = 1;
    PLL ans;
    for(int i = 0; i < n; ++i){
        ans = mid(l,r);
        // printf("l = (%lld/%lld), r = (%lld/%lld) and mid = (%lld,%lld)\n",l.first,l.second,r.first,r.second,ans.first,ans.second);
        if(c == 1)r=ans;
        else l = ans;
        c = 1-c;
    }
    cout << ans.first << " " << ans.second << " ";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
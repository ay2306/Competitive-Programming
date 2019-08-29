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

void solve(){
    ll a;
    scanf("%lld",&a);
    ll c = 1;
    ll d1 = 0,d2=0,mxi=0;
    for(int i = 1; i < 64; ++i){
        ll c = (1LL << i)-1;
        if(a*i > c){
            ll profit = a*i - c;
            if(profit > mxi){
                d2 = i;
                mxi = profit;
            }
            d1 = i;
        }else{
            break;
        }
    }
    printf("%lld %lld\n",d1,d2);
}

int main(){
    int t = 1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
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
// #define MAXN 25
using namespace std;

struct Query{
    ll l,r,index;
};
ll K = 320;
const int MAXN = 2e5 + 5;
const int MAXN2 = 1e6+10;
ll a[MAXN],cnt[MAXN2],n,m,ans[MAXN],c1;
ll pos,min1,neg;
long long int cans;
struct Query q[MAXN];

bool compare(Query x, Query y){
    if(x.l/K != y.l/K)return x.l < y.l;
    if((x.l/K)&1)return x.r < y.r;
    return (x.r > y.r);
}

int main(){
    FAST
    FILE_READ
    cin >> n;
    loop(i,0,n)cin >> a[i];
    cin >> m;
    loop(i,0,m){
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }
    K = sqrt(n);
    // K = 1000;
    sort(q,q+m,compare);
    int curL = 1; int curR = 0;
    for(int i = 0; i < m; ++i){
        // printf("QUERY = {%d, %d}\n",q[i].l,q[i].r);
        int L = q[i].l-1, R = q[i].r-1;
        while(curL > L){
            curL--;
            // cout << L << " " << a[L] << "\n";
            if(a[curL] == -1)min1++;
            if(a[curL] > 1)pos++;
            if(a[curL] < -1)neg++;
        }
        while(curL < L){
            // cout << L << " " << a[L] << "\n";
            if(a[curL] == -1)min1--;
            if(a[curL] > 1)pos--;
            if(a[curL] < -1)neg--;
            curL++;
        }while(curR > R){
            // cout << R << " " << a[R] << "\n";
            if(a[curR] == -1)min1--;
            if(a[curR] > 1)pos--;
            if(a[curR] < -1)neg--;
            curR--;
        }while(curR < R){
            curR++;
            // cout << R << " " << a[R] << "\n";
            if(a[curR] == -1)min1++;
            if(a[curR] > 1)pos++;
            if(a[curR] < -1)neg++;    
        }
        // cout << neg << " " << pos << " " << min1 << "\n";
        if(neg%2 == 0)cans=neg+pos;
        if(neg%2 == 1){
            if(min1 > 0)cans = neg+1+pos;
            else cans = neg+pos-1;
        }
        if(cans == 0){
            cans = 1;
        }
        ans[q[i].index] = cans;
    }
    loop(i,0,m){cout << ans[i];if(i+1 != m)cout << "\n";}
    fflush(stdout);
    return 0;
}
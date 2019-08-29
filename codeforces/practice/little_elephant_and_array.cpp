/*
 ____________________________________________________________
|                                                            |
|                   Author: alexey_kuldoshin                 |
|        Copied in order to learn about sqrt decomp          |
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
using namespace std;

struct Query{
    int l,r,index;
};

const int MAXN = 1e5 + 5;
int K = 320;
int a[MAXN], cnt[MAXN], ans[MAXN], cans, n,m;
Query q[MAXN];

inline void add(int index){
    if(a[index] >= MAXN){return ;}
    cans-=(cnt[a[index]]==a[index]);
    cnt[a[index]]++;
    cans+=(cnt[a[index]]==a[index]);
}

inline void del(int index){
    if(a[index] >= MAXN){return ;}
    cans-=(cnt[a[index]]==a[index]);
    cnt[a[index]]--;
    cans+=(cnt[a[index]]==a[index]);
}

inline int getAns(){
    return cans;
}

bool comp(Query x, Query y){
    if(x.l/K != y.l/K)return x.l < y.l;
    return ((x.l/K) & 1)?(x.r < y.r):(x.r > y.r); 
}

signed main(){
    cin >> n >> m;
    loop(i,0,n)cin >> a[i];
    K = (int)sqrt(n);
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        q[i].l = a;
        q[i].r = b;
        // cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }
    sort(q,q+m,comp);
    int curL = 1, curR = 0;
    // add(0);
    loop(i,0,m){
        int L = q[i].l - 1, R = q[i].r - 1;
        while(curL > L)add(--curL);
        while(curR < R)add(++curR);
        while(curL < L)del(curL++);
        while(curR > R)del(curR--);
        ans[q[i].index] = getAns();
    }
    loop(i,0,m){
        cout << ans[i] << endl;
    }
}



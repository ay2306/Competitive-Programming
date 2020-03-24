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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
const ll N = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int SZ = 340;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Q{
    int l,r,ind;
    int64_t ord;
    Q(){}
    Q(int a, int b, int c):l(a),r(b),ind(c){}
    inline void cal(){
        ord = gilbertOrder(l,r,21,0);
    }
    bool operator <(const Q &rhs){
        return ord < rhs.ord;
    }
};

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    V<ll> p(n+1,0LL);
    loop(i,0,n){
        int a;
        scanf("%d",&a);
        p[i+1]=p[i]^a;
    }
    SZ = sqrt(n)+1;
    vector<Q> q(m);
    loop(i,0,m){scanf("%d%d",&q[i].l,&q[i].r);q[i].ind=i;q[i].cal();}
    sort(all(q));
    ll ans = 0;
    V<ll> res(m);
    V<ll> cnt((1<<21),0);
    int l = 0,r = 1;
    ans = (p[1] == k);
    cnt[p[0]]++;cnt[p[1]]++;
    for(Q &qi : q){
        int L = qi.l-1;
        int R = qi.r;
        while(l > L){
            l--;
            ans+=cnt[p[l]^k];
            cnt[p[l]]++;
        }
        while(l < L){
            cnt[p[l]]--;
            ans-=cnt[p[l]^k];
            l++;
        }
        while(r > R){
            cnt[p[r]]--;
            ans-=cnt[p[r]^k];
            r--;
        }
        while(r < R){
            r++;
            ans+=cnt[p[r]^k];
            cnt[p[r]]++;
        }
        res[qi.ind] = ans;
    }
    loop(i,0,m)printf("%lld\n",res[i]);
    return 0;
}
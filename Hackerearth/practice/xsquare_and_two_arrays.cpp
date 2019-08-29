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

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
}

class SegmentTree{
    ll *tree;
    ll *arr;
    int n;
    public:
    SegmentTree(ll *arr, int n){
        this->n = n;
        this->tree = new ll[4*n];
        this->arr = arr;
        build(0,0,n-1);
    }
    void build(int node, int l, int r ){
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
    ll query(int x, int y,int node, int l, int r){
        if(y < l || x > r)return 0;
        if(x <= l && y >= r)return tree[node];
        int mid = (l+r)/2;
        ll p1 = query(x,y,2*node+1,l,mid);
        ll p2 = query(x,y,2*node+2,mid+1,r);
        return p1+p2;
    }
};

int main(){
    int n,q;
    cin >> n >> q;
    ll* a1 = new ll[n];
    ll* a2 = new ll[n];
    ll* b1 = new ll[n];
    ll* b2 = new ll[n];
    loop(i,0,n){
        if(i%2 == 0){
            cin >> a1[i];
            a2[i] = 0;
        }else{
            cin >> a2[i];
            a1[i] = 0;
        }
    }
    loop(i,0,n){
        if(i%2 == 0){
            cin >> b1[i];
            b2[i] = 0;
        }else{
            cin >> b2[i];
            b1[i] = 0;
        }
    }
    SegmentTree sta1(a1,n);
    SegmentTree sta2(a2,n);
    SegmentTree stb1(b1,n);
    SegmentTree stb2(b2,n);
    while(q--){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        r--;
        ll ans = 0;
        if(t == 0){
            if(l%2 == 0){
                ans = stb1.query(l,r,0,0,n-1) + sta2.query(l,r,0,0,n-1);
            }else{
                ans = stb2.query(l,r,0,0,n-1) + sta1.query(l,r,0,0,n-1);
            }
        }else{
            if(l%2 == 0){
                ans = sta1.query(l,r,0,0,n-1) + stb2.query(l,r,0,0,n-1);
            }else{
                ans = sta2.query(l,r,0,0,n-1) + stb1.query(l,r,0,0,n-1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
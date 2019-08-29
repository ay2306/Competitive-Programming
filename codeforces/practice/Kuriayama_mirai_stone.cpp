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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

class SEGMENT_TREE{
    ull *tree;
    ull *arr;
    ull n;
    ull hn;
public:
    SEGMENT_TREE(ull *arr, ull n){
        this->arr = arr;
        this->hn = 0;
        this->n = n;
        this->tree = (ull*)calloc(4*n,sizeof(ull));
    }
    void build(ull node,ull start, ull end){
        if(node > hn)hn = node;
        if(start == end){
            tree[node] = arr[start];
            return ;
        }
        ull mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    ull query(ull node, ull start, ull end, ull l, ull r){
        if(r < start || l > end)return 0;
        if(l<=start && r>=end)return tree[node];
        ull mid = (start+end)/2;
        ull p1 = query(2*node,start,mid,l,r);
        ull p2 = query(2*node+1,mid+1,end,l,r);
        return p1+p2;
    }
    void dis(){
        for(ull i = 1; i <= hn; ++i)cout << tree[i] << " ";
        cout << endl;
    }

};

int main(){
    FAST
    ull n;
    cin >> n;
    ull *arr = new ull[n+1];
    for(ull i = 1; i <= n; ++i)cin >> arr[i];
    SEGMENT_TREE v(arr,n);
    v.build(1,1,n);
    sort(arr+1,arr+n+1);
    SEGMENT_TREE u(arr,n);
    u.build(1,1,n);
    // cout << "HELLO";
    ull q;
    // cin >> q;
    // v.dis();
    cin >> q;
    while(q--){
        ull a,b,c;
        cin >> a >> b >> c;
        if(a==1)cout << v.query(1,1,n,b,c) << endl;
        if(a==2)cout << u.query(1,1,n,b,c) << endl;
    }
    return 0;
}
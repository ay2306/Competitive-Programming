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

    V<V<ll> > primes;
    unordered_map<ll,priority_queue<ll,V<ll>,greater<ll> > > dp;
    struct node{
        ll val;
        priority_queue<ll,V<ll>,greater<ll> > p;
        node(){}
        node(ll a){
            if(a == 1){
                val = 1;
            }
            else{
                SET(a);
            }
        }
        void SET(ll a){
            ll val = a;
            V<ll> &p1 = primes[a];
            for(auto i: p1){
                while(a > 1 && a%i == 0){
                    a/=i;
                    p.push(i);
                }
            }
            if(p1.size() == 0)p.push(a);
        }
    };

    V<ll> tree;
    V<ll> sumtree;
    V<node> arr;
    ll n;
    void build(ll node = 0, ll start = 0, ll end = n-1){
        if(start == end){
            tree[node] = ((arr[start].p.size() > 0)?arr[start].p.top():1);
            sumtree[node] = arr[start].val;
            return;
        }
        build(2*node+1,start,(start+end)/2);
        build(2*node+2,(start+end)/2+1,end);
        tree[node] = max(tree[2*node+1],tree[2*node+2]);
        sumtree[node] = sumtree[2*node+1]+sumtree[2*node+2];
    }

    void update(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
        if(end < start)return;
        if(l > end || r < start)return;
        if(sumtree[node] == end-start+1)return;
        if(l <= start && end <= r && start == end){
            arr[start].val/=arr[start].p.top();
            arr[start].p.pop();
            tree[node] = ((arr[start].p.size() > 0)?arr[start].p.top():1);
            sumtree[node] = arr[start].val;
            return;
        }
        update(l,r,2*node+1,start,(start+end)/2);
        update(l,r,2*node+2,(start+end)/2+1,end);
        tree[node] = max(tree[2*node+1],tree[2*node+2]);
        sumtree[node] = sumtree[2*node+1]+sumtree[2*node+2];
    }

    ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
        if(l > end || r < start)return 0;
        if(sumtree[node] == end-start+1)return 1;
        if(l <= start && end <= r){
            return tree[node];
        }
        ll p1 = query(l,r,2*node+1,start,(start+end)/2);
        ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
        return max(p1,p2);
    }

    void solve(){
        ll m;
        cin >> n >> m;
        arr = V<node> (n);
        tree = V<ll> (4*n);
        sumtree = V<ll> (4*n);
        loop(i,0,n){
            ll a;
            cin >> a;
            arr[i] = node(a);
        }
        build();
        while(m--){
            ll a,b,c;
            cin >> a >> b >> c;
            b--;
            c--;
            if(a == 0){
                update(b,c);
            }else{
                cout << query(b,c) << " ";
            }
            // printf("\n");
            // loop(i,0,n){
            //     printf("%lld ",arr[i].val);
            // }
            // printf("\n");
            // loop(i,0,n){
            //     printf("%lld ",((arr[i].p.size() > 0)?arr[i].p.top():1));
            // }
            // printf("\n");
        }
        cout << "\n";
    }

    int main(){
        // FILE_READ_IN
        FAST
        const ll maxn = 1e6 + 10;
        primes = V<V<ll> > (maxn,V<ll> ());
        for(ll i = 2; i < maxn; ++i){
            if(primes[i].size() == 0){
                for(ll j = 2; i*j < maxn; ++j)primes[i*j].pb(i);
            }
        }
        int t = 1;
        cin >> t;
        while(t--)solve();
        return 0;
    }
    #include <bits/stdc++.h>
    //For ordered_set
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
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
    #define D double
    using namespace std;
    // For ordered_set
    using namespace __gnu_pbds;
    template <typename T>
    using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
    const ll maxn = 1e5;
    const ll inf = 1e9;
    const double pi = acos(-1);

    vector<pair<double,PLL>> edges;
    vector<ll> Rank;
    vector<ll> parent;
    int findParent(int x){
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
    return x;
    }
    void UNION(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(Rank[a] < Rank[b]){
            parent[a]=b;
        }else if(Rank[a] > Rank[b]){
            parent[b] = a;
        }else{
            parent[a] = b;
            Rank[b]++;
        }
    }
    double krushkal(){
        sort(edges.begin(),edges.end());
        double ans = 0;
        for(auto &i: edges){
            if(findParent(i.second.first) != findParent(i.second.second)){
                UNION(i.second.first,i.second.second);
                ans+=i.first;
            }
        }
        return ans;
    }

    void solve(){
        int n;
        cin >> n;
        V<P<D,D>> arr(n);
        parent = V<ll>(n,0);
        Rank = V<ll> (n,0);
        edges = V<P<double,PLL>> ();
        loop(i,0,n){
            D a,b;
            cin >> a >> b;
            arr[i] = mp(a,b);
            parent[i] = i;
        }
        loop(i,0,n){
            loop(j,0,n){
                if(fabs(arr[i].F-arr[j].F)+fabs(arr[i].S-arr[j].S) == 1){
                    edges.pb(mp(0.0,mp(i,j)));
                }else{
                    double dis = (arr[i].F-arr[j].F)*(arr[i].F-arr[j].F) + (arr[i].S-arr[j].S)*(arr[i].S-arr[j].S);
                    dis = sqrt(dis);
                    edges.pb(mp(dis,mp(i,j)));
                    edges.pb(mp(dis,mp(j,i)));
                }
            }
        }
        double ans = krushkal();
        printf("%.6f\n",ans);
    }
    int main(){
        int t;
        cin >> t;
        while(t--)solve();
    return 0;
    }
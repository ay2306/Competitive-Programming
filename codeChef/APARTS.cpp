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
#define D deque
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
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m;
V<V<int>> ans;
class ST{
    V<PII> arr;
    V<int> tree;
    V<int> lazy;
    int sz;
    public:
        ST(){}
        ST(int i, int j, int c){
            sz = 0;
            while(i < n && j < m && j >= 0){
                arr.pb(mp(i,j));
                i++;
                j+=c;
                sz++;
            }
            tree = V<int> (4*n,1);
            lazy = V<int> (4*n,0);
        }
        void update(int i, int j,int val = -1, int node = 0, int start = 0, int end = 0){
            if(i < 0 && j < 0){
                i++;
                j++;
                int ind = lower_bound(arr.begin(),arr.end(),mp(-i,-j)) - arr.begin();
                printf("ind = %d\n",ind);
                if(ind < arr.size()-1){
                    update(ind+1,sz-1,0,node,start,sz-1);
                }
                update(ind,ind,1,node,start,sz-1);
                return;
            }
            if(lazy[node]){
                tree[node] = 0;
                if(start != end){
                    lazy[2*node] = 1;
                    lazy[2*node+1] = 1;
                }
                lazy[node] = 0;
            }
            if(start > j || end < i)return;
            if(i <= start && end <= j){
                tree[node] = val;
                if(start != end){
                    lazy[2*node] = 1;
                    lazy[2*node+1] = 1;
                }
                return ;
            }
            update(i,j,val,2*node,start,((start+end) >> 1));
            update(i,j,val,2*node+1,((start+end) >> 1)+1,end);
        }
        void traverse(int node = 0, int start = 0, int end = -1){
            if(end == -1)end = sz-1;
            if(lazy[node]){
                if(start != end){
                    tree[node] = 0;
                    lazy[2*node] = 1;
                    lazy[2*node+1] = 1;
                }
                lazy[node] = 0;
            }
            if(start == end){
                ans[arr[start].F][arr[start].S] = (tree[node] & ans[arr[start].F][arr[start].S]);
                printf("node = (%d,%d) , turned = %d\n",arr[start].F,arr[start].S,ans[arr[start].F][arr[start].S]);
                return;
            }
            traverse(2*node,start,((start+end) >> 1));
            traverse(2*node+1,((start+end) >> 1)+1,end);
        }
        void listThem(){
            for(auto i: arr){
                printf("(%d, %d) : ",i.F,i.S);
            }
            printf("\n");
        }
};

void solve(){
    cin >> n >> m;
    V<P<int,PII>> arr;
    ans = V<V<int>> (n,V<int> (m,1));
    unordered_map<int,ST> bd;
    unordered_map<int,ST> b;
    unordered_map<int,ST> br;
    loop(i,0,n){
        loop(j,0,m){
            int val;
            cin >> val;
            arr.pb(mp(val,mp(i,j)));
            if(bd.find(i+j) == bd.end()){
                bd[i+j] = ST(i,j,-1);
            }
            if(b.find(j) == b.end()){
                b[j] = ST(i,j,0);
            }
            if(br.find(i-j) == br.end()){
                br[i-j] = ST(i,j,1);
            }
        }
    }
    sort(all(arr));
    for(auto i: arr){
        printf("Going for (%d, %d, %d)\n",i.F,i.S.F,i.S.S);
        bd[i.S.F+i.S.S].update(-i.S.F-1,-i.S.S-1);
        bd[i.S.F+i.S.S].traverse();
        b[i.S.S].update(-i.S.F-1,-i.S.S-1);
        b[i.S.S].traverse();
        br[i.S.F-i.S.S].update(-i.S.F-1,-i.S.S-1);
        br[i.S.F-i.S.S].traverse();;
        // for(auto i: br){
        //     // printf("measure: br : %d\n",i.F);
        //     i.S.traverse();
        //     // i.S.listThem();
        // }
        // for(auto i: b){
        //     // printf("measure: b : %d\n",i.F);
        //     i.S.traverse();
        //     // i.S.listThem();
        // }
        // for(auto i: bd){
        //     // printf("measure: bd : %d\n",i.F);
        //     i.S.traverse();
        //     // i.S.listThem();
        // }
        loop(i,0,n){
            loop(j,0,m){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}

int main(){
    // FAST
    FILE_READ_IN
    FILE_READ_OUT
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}
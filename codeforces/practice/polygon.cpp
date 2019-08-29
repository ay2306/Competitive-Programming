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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

struct point{
    ll x;
    ll y;
    bool operator<(const point rhs){
        return (this->x < rhs.x || (this->x == rhs.x && this->y < rhs.y));
    }
};
bool cw(point &a, point &b, point &c){
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) <= 0;
}
bool ccw(point &a, point &b, point &c){
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) >= 0;
}
V<point> ans;
void graham_scan(V<point> &arr){
    ans = V<point> ();
    if(arr.size() == 1){
        ans.pb(arr[0]);
        return;
    }
    sort(all(arr));
    point p1 = arr[0];
    point p2 = arr.back();
    V<point> up,down;
    up.pb(p1);
    down.pb(p1);
    loop(i,1,arr.size()){
        if(i == arr.size()-1 || cw(p1,arr[i],p2)){
            while(up.size() >= 2 && !cw(up[up.size()-2],up[up.size()-1],arr[i]))up.pop_back();
            up.pb(arr[i]);
        }
        if(i == arr.size()-1 || ccw(p1,arr[i],p2)){
            while(down.size() >= 2 && !ccw(down[down.size()-2],down[down.size()-1],arr[i]))down.pop_back();
            down.pb(arr[i]);
        }
    }
    for(int i = 0; i < up.size(); ++i){
        ans.pb(up[i]);
    }
    for(int i = down.size()-2; i > 0; --i){
        ans.pb(down[i]);
    }
}

int main(){
    // FILE_READ_IN
    FAST
    V<point> a,b,both;
    int n;
    cin >> n;
    loop(i,0,n){
        point k;
        cin >> k.x >> k.y;
        a.pb(k);
        both.pb(k);
    }
    int m;
    cin >> m;
    loop(i,0,m){
        point k;
        cin >> k.x >> k.y;
        b.pb(k);
        both.pb(k);
    }
    graham_scan(both);
    map<PII,int> o;
    loop(i,0,ans.size()){
        o[mp(ans[i].x,ans[i].y)]++;
    }
    for(int i = 0; i < b.size(); ++i){
        PII k = mp(b[i].x,b[i].y);
        if(o[k] > 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
   return 0;
}
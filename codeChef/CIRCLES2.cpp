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
const double eps = 1e-9;
const double pi = acos(-1);

struct circle{
    double x;
    double y;
    double r;
    bool inside(pair<double,double> a, bool print = false){
        double dis = (x-a.F)*(x-a.F) + (y-a.S)*(y-a.S);
        if(print){
            printf("distance from c2 =  %.10f\n",sqrt(dis));
        }
        dis = sqrt(dis);
        if(dis - r > 1e-7){
            return false;
        }
        return true;
    }
};

struct line{
    double m;
    double c;
    void _init(double x1,double y1,double x2, double y2){
        // cout << x1 << " " << y1 << " " << x1 << " " << y1 << "\n";
        m = (y2-y1)/(x2-x1);
        c = y1 - m*x1;
        // printf("LINE SET: y = %f x + %f\n",m,c);
    }
    double y(double x){
        return m*x+c;
    }
};

void solve(){
    circle c1,c2;
    scanf("%lf %lf %lf %lf %lf %lf",&c1.x,&c1.y,&c1.r,&c2.x,&c2.y,&c2.r);
    // cin >> c1.x >> c1.y >> c1.r;
    // cin >> c2.x >> c2.y >> c2.r;
    if(c1.x == c2.x && c1.y == c2.y){
        if(c1.r > c2.r){
            printf("YES\n%.10f %.10f\n",c1.x+c1.r,c1.y);
        }else{
            printf("NO\n");
        }
        return ;
    }
    if(c1.x == c2.x){
        if(!c2.inside(mp(c1.x-c1.r,c1.y))){
            printf("YES\n%.10f %.10f\n",c1.x-c1.r,c1.y);
        }else if(!c2.inside(mp(c1.x+c1.r,c1.y))){
            printf("YES\n%.10f %.10f\n",c1.x+c1.r,c1.y);
        }else{
            printf("NO\n");
        }
        return ;
    }
    if(c1.y == c2.y){
        if(!c2.inside(mp(c1.x,c1.y-c1.r))){
            printf("YES\n%.10f %.10f\n",c1.x,c1.y-c1.r);
        }else if(!c2.inside(mp(c1.x,c1.y+c1.r))){
            printf("YES\n%.10f %.10f\n",c1.x,c1.y+c1.r);
        }else{
            printf("NO\n");
        }
        return ;
    }
    double l,r;
    bool inc = true;
    if(c2.x < c1.x){
        r = c1.x+c1.r;
        l = c1.x;
    }else{
        r = c1.x;
        l = c1.x-c1.r;
        inc = false;
    }
    line l1;
    l1._init(c1.x,c1.y,c2.x,c2.y);
    ll lst;
    while(r-l > eps){
        // printf("l = %f, r = %f\n",l,r);
        double x = (r+l)/2;
        double y = l1.y(x);
        if(c1.inside(mp(x,y))){
            if(inc){
                l = x;
            }else{
                r = x;
            }
        }else{
            if(inc){
                r = x;
            }else{
                l = x;
            }
        }
    }
    // c1.inside(mp(l,l1.y(l)),true);
    // printf("CHECK: %.10f %.10f\n",l,l1.y(l));
    if(!c2.inside(mp(l,l1.y(l)))){
        printf("YES\n%.10f %.10f\n",l,l1.y(l));
    }else{
        printf("NO\n");
    }
}

int main(){
    FAST
    int t;
    scanf("%d",&t);
   while(t--){
       solve();
   }
   return 0;
}
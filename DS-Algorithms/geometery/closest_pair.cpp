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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

class pt {
public:
    long long int x, y, id;
    pt():x(0),y(0),id(-1){}
    pt(long long int a,long long int b,long long  int c):x(a),y(b),id(c){}
};
vector<pt> points;
int u ,v;
double bestmin = inf;
bool cmp_x(const pt &a, const pt &b){
    return (a.x < b.x);
}
bool cmp_y(const pt &a, const pt &b){
    return (a.y < b.y);
}

double dis(const pt &a, const pt &b){
    return sqrt(((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y)));
}

double brute(int l, int r){
    double mn = inf;
    for(int i = l; i <= r; ++i){
        for(int j = i+1; j <=r; ++j){
            double dist = dis(points[i],points[j]);
            if(mn > dist){
                mn = dist;
                if(mn < bestmin){
                    bestmin = mn;
                    u = points[i].id;
                    v = points[j].id;
                }
            }
        }
    }
    return mn;
}

double findClose(vector<pt> a, int k, double d){
    sort(a.begin(),a.end(),cmp_y);
    double mn;
    mn = d;
    k = a.size();
    for(int i = 0; i < k; ++i){
        for(int j = i+1; j < k && abs(a[j].y - a[i].y) < mn; ++j){
            double dist = dis(a[i],a[j]);
            if(abs(a[j].y - a[i].y) >= mn)break;
            if(mn > dist){
                mn = dist;
                if(mn < bestmin){
                    bestmin = mn;
                    u = a[i].id;
                    v = a[j].id;
                }
            }
        }
    }
    return mn;
}

double closepoints(int l, int r){
    int mid = ((l+r) >> 1);
    if(r-l+1 <= 3){
        return brute(l,r);
    }
    double left = closepoints(l,mid);
    double right = closepoints(mid+1,r);
    // printf("(%d ==== %d) left = %.6f, right = %.6f close\n",l,r,left,right);
    double m = min(left,right);
    vector<pt> pot;
    mid = points[mid].x;
    for(int i = l; i <= r; ++i){
        if(abs(mid-points[i].x) < m){
            pot.pb(points[i]);
        }
    }
    return min(m,findClose(pot,int(pot.size()),m));
}
int main(){
    FAST
   int n;
   cin >> n;
   points = vector<pt> (n);
   loop(i,0,n){
       cin >> points[i].x >> points[i].y;
       points[i].id = i;
   }
   sort(all(points),cmp_x);
//    for(auto i: points){
//        printf("(%lld , %lld) ", i.x, i.y);
//    }
//    printf("\n");
   closepoints(0,n-1);
   if(u > v)swap(u,v);
   printf("%d %d %.6f\n",u,v,bestmin);
   return 0;
}
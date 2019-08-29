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
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

struct chtDynamics{
    bool isMax;
    chtDynamics(bool isthisMax = false):isMax(isthisMax){}
    struct line{
        ll m,b;
        ld x;
        ll val;
        enum Type{Line,maxQuery,minQuery} type;
        line(ll _m = 0, ll _b = 0): m(_m),b(_b),val(0),x(-inf),type(Type::Line){}
        ll eval(ll x)const{return m*x + b;}//x*speed + distance_covered_atStart - time_started*speed;
        bool parallel(const line &l)const{return m == l.m;}
        ld intersect(const line &l)const{
            return (parallel(l)?inf:1.0*(l.b-b)/(m-l.m));
        }
        bool operator<(const line &l)const{
            if(l.type == Line)return m < l.m;
            if(l.type == maxQuery)return x < l.val;
            if(l.type == minQuery)return x > l.val;
        }
    };
    set<line> hull;
    typedef set<line>::iterator iter;
    bool cPrev(iter it){return it != hull.begin();}
    bool cNext(iter it){return it != hull.end() && next(it) != hull.end();}
    bool bad(const line &l1, const line &l2, const line &l3){
        return l1.intersect(l3) <= l1.intersect(l2);
    }
    bool bad(iter it){n
        return cPrev(it) && cNext(it) && ((isMax && bad(*prev(it),*it,*next(it))) || (!isMax && bad(*next(it),*it,*prev(it))));
    }
    iter update(iter it){
        if(isMax && !cPrev(it))return it;
        if(!isMax && !cNext(it))return it;
        ld x = it->intersect(isMax?*prev(it):*next(it));
        line tmp(*it);
        tmp.x = x;
        it = hull.erase(it);
        return hull.insert(it,tmp);
    }
    void addLine(ll m, ll b){
        line l(m,b);
        iter it = hull.lower_bound(l);
        if(it != hull.end() && l.parallel(*it)){
            if(isMax && it->b < b)it=hull.erase(it);
            if(!isMax && it->b > b)it=hull.erase(it);
            else return;
        }
        it = hull.insert(it,l);
        if(bad(it))return (void)hull.erase(it);
        while(cPrev(it) && bad(prev(it)))hull.erase(prev(it));
        while(cNext(it) && bad(next(it)))hull.erase(next(it));
        it = update(it);
        if(cPrev(it))update(prev(it));
        if(cNext(it))update(next(it));
    }
    ll getBest(ll x) const{
        if(isMax && hull.empty())return -inf;
        if(!!isMax && hull.empty())return inf;
        line q;
        q.val = x;
        q.type = isMax?line::Type::maxQuery:line::Type::minQuery;
        iter it = hull.lower_bound(q);
        if(isMax)it--;
        return it->eval(x);
    }
    void displayLines(){
        for(auto &a: this->hull)printf("y = %lld x + %lld\n",a.m,a.b);
    }
};

int main(){

   return 0;
}
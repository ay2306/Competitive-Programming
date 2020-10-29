#include<bits/stdc++.h>
using namespace std;

# define C continue;

# define ll long long
# define ld long double
#define int long long
# define pb push_back
# define I insert
# define PQ priority_queue

# define vi vector < int >
# define vll vector < ll >
# define vc vector < char >
# define vb vector < bool >
# define vs vector < string >

# define vvi vector < vector < int > >
# define vvll vector < vector < ll > >
# define vvc vector < vector < char > >
# define vvb vector < vector < bool > >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >

# define vpii vector < pair < int , int > >
# define vpll vector < pll >

# define F first
# define S second

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 1 , 0 , -1 , -1 , 1 , 1 } ;
const int dy[] = { 0 , 1 , 0 , -1 , -1 , 1 , -1 , 1 } ;

const ld pie = 3.1415926535897932384626 ;
const ll mod = 1e9 + 7 ;

/// Tip : If a and b are positive integers ; we may say - ceil (a/b) = 1 + floor ( (a-1)/b ) .
/// Start using lower bound !!

const int N = 1e5 + 10 ;

int n ;
ll s ;

vi g[N] ;
vector < array < int , 3 > > ed ;

void read ()
{
    cin >> n >> s ;
    ed.resize ( n - 1 ) ;

    for ( int i = 1 ; i < n ; i ++ )
    {
        int a , b , w ;
        cin >> a >> b >> w ;

        g[a].pb ( b ) ;
        g[b].pb ( a ) ;

        ed[i - 1] = { a , b , w } ;
    }
}

int lev[N] ;
int sz[N] ;

void dfs ( int node )
{
    int deg = g[node].size() ;
    if ( deg == 1 && node != 1 )
        sz[node] = 1 ;

    for ( auto &i : g[node] )
    {
        if ( i == 1 ) C ;
        if ( lev[i] ) C ;

        lev[i] = 1 + lev[node] ;
        dfs ( i ) ;

        sz[node] += sz[i] ;
    }
}

struct dt{
    int w, sz;
    dt(int _w, int _sz):w(_w),sz(_sz){}
    bool operator<(const dt &rhs)const{
        return ((w-w/2)*sz) < (rhs.w-rhs.w/2)*rhs.sz;   
    }
    bool operator>(const dt &rhs)const{
        return ((w-w/2)*sz) > (rhs.w-rhs.w/2)*rhs.sz;   
    }
    bool operator==(const dt &rhs)const{
        return ((w-w/2)*sz) == (rhs.w-rhs.w/2)*rhs.sz;   
    }
};

void solve ( int test_case )
{
    read () ;
    dfs ( 1 ) ;

    multiset < dt > t ;

    for ( auto &temp : ed )
    {
        int a = temp[0] ;
        int b = temp[1] ;
        int w = temp[2] ;

        if ( lev[b] != lev[a] + 1 )
            swap ( a , b ) ;

        t.emplace (  w , sz[b]  ) ;
        s -= 1LL * w * sz[b] ;
    }

    int moves = 0 ;

    while ( s < 0 )
    {
        // cout << s << "\n";
        auto it = t.rbegin() ;
        auto temp = *it;
        t.erase ( prev(t.end()) ) ;

        ll w = temp.w ;
        ll leaves = temp.sz ;

        ll cur_cost = w*leaves ;

        w >>= 1 ;
        t.emplace (  w , leaves  ) ;

        ll new_cost = w*leaves ;
        ll reduce = abs ( cur_cost - new_cost ) ;

        s += reduce ;
        moves ++ ;
    }

    cout << moves ; line ;
}

void clear_data ()
{
    for ( int i = 1 ; i <= n ; i ++ )
    {
        sz[i] = 0 ;
        lev[i] = 0 ;

        g[i].clear() ;
    }

    ed.clear() ;
}

signed main()
{
    // fast
    int t = 1;
    cin >> t;

    for ( int i = 1 ; i <= t ; i ++ )
    {
        solve ( i ) ;
        clear_data () ;
    }

    return 0;
}

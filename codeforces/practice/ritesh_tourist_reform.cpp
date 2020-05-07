#include<bits/stdc++.h>
using namespace std;

# define C continue;
# define R return

# define D double
# define I insert
# define ll long long
# define ld long double

# define ull unsigned long long
# define ui unsigned int

# define pb push_back
# define pf push_front

# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvs vector < vs >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >

# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 1 , 0 } ;
const int dy[] = { 0 , 1 , 0 , -1 } ;

const ld pie = 3.1415926535897932384626 ;
const ll mod = 1e9 + 7 ;

/// Tip : If a and b are positive integers ; we may say - ceil (a/b) = 1 + floor ( (a-1)/b ) .

const int N = 4e5 + 10 ;

vpii original_graph[N] ;
vi g[N] ;

int n , m ;

vpii ed ;
vpii ans_ed ;

void read ()
{
    cin >> n >> m ;

    ed.resize ( m ) ;
    ans_ed.resize ( m ) ;

    for ( int i=0 ; i < m ; i ++ )
    {
        int a , b;
        cin >> a >> b ;

        a -- ; b -- ;

        original_graph[a].pb ( { i , b } ) ;
        original_graph[b].pb ( { i , a } ) ;

        ed[i] = { a , b } ;
    }
}

bool vis[N] ;
set < pii > taken_edge ;

void dfs_init ( int node )
{
    vis[node] = 1 ;

    for ( auto &temp : original_graph[node] )
    {
        int i = temp.S ;
        int id = temp.F ;

        temp = { node , i } ;
        if ( taken_edge.count ( temp ) ) C ;

        g[node].pb ( i ) ;
        ans_ed[id] = temp ;

        taken_edge.I ( { i , node } ) ;

        if ( vis[i] ) C ;
        dfs_init ( i ) ;
    }
}

int dis_time[N] , low_time[N] ;

stack < int > temp ;
bool in_stack[N] ;

# define time wlkdlwkmedlkwmeldkwmelkdw
int time = 1 ;

int parent[N] ;


void start_of_scc ( int src )
{
    int z = 0 ;

    while ( true )
    {
        int node = temp.top() ;
        temp.pop( ) ;

        in_stack[node] = false ;

        parent[src] -- ;

        if ( node == src ) break ;
        parent[node] = src ;
    }
}

void dfs ( int node )
{
    dis_time[node] = time ;
    low_time[node] = time ;

    time ++ ;

    in_stack[node] = 1 ;
    temp.push ( node ) ;

    for ( auto &i : g[node] )
    {
        if ( in_stack[i] )
        {
            low_time[node] = min ( low_time[node] , low_time[i] ) ;
        }

        else if ( dis_time[i] == 0 )
        {
            dfs ( i ) ;
            low_time[node] = min ( low_time[node] , low_time[i] ) ;
        }
    }

    if ( low_time[node] == dis_time[node] )
    {
        start_of_scc ( node ) ;
    }
}

void SCC ()
{
    for ( int i=0 ; i < n ; i ++ )
    {
        if ( dis_time[i] ) C ;
        dfs ( i ) ;
    }
}

int find_parent ( int node )
{
    if ( parent[node] < 0 )
        return node ;

    return parent[node] ;
}

vi final_g[N] ;
int final_parent[N] ;

void final_dfs ( int node )
{
    vis[node] = 1 ;

    for ( auto &i : final_g[node] )
    {
        if ( vis[i] ) C ;

        final_parent[i] = node ;
        final_dfs ( i ) ;
    }
}

void solve ( int test_case )
{
    read () ;
    dfs_init ( 0 ) ;

    SCC () ;

    int maxx = 0 ;
    int root = 0 ;

    for ( int i=0 ; i < n ; i ++ )
    {
        int p = find_parent ( i ) ;
        if ( p != i ) C ;

        int z = -parent[p] ;

        if ( z > maxx )
            maxx = z , root = p ;
    }

    for ( int i=0 ; i < m ; i ++ )
    {
        int a = ed[i].F ;
        int b = ed[i].S ;

        int p1 = find_parent ( a ) ;
        int p2 = find_parent ( b ) ;

        if ( p1 == p2 ) C ;

        final_g[p1].pb ( p2 ) ;
        final_g[p2].pb ( p1 ) ;
    }

    for ( int i=0 ; i < n ; i ++ )
        vis[i] = false ;

    final_dfs ( root ) ;

    for ( int i=0 ; i < m ; i ++ )
    {
        int a = ed[i].F ;
        int b = ed[i].S ;

        int p1 = find_parent ( a ) ;
        int p2 = find_parent ( b ) ;

        if ( p1 == p2 ) C ;

        /// I want edge to be from a to b
        /// This will not be the case if final_parent[p2] == p1

        if ( final_parent[p2] == p1 )
            swap ( a , b ) ;

        ans_ed[i] = { a , b } ;
    }

    cout << maxx ; line ;
    for ( int i=0 ; i < m ; i ++ )
    {
        cout << ans_ed[i].F + 1 << " " << ans_ed[i].S + 1 , line ;
    }
}

int main()
{fast
    int t = 1;
    // cin >> t;

    for ( int i = 1 ; i <= t ; i ++ )
    {
        solve ( i ) ;
    }

    return 0;
}
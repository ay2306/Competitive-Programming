#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

vector < pair < int , int > > parent ( N ) ;

# define rank owjeodkmwlekdmlwkemdlkwe
# define F first
# define S second
# define line cout << "\n" ;

bool bipartite[N] ;
int rank[N] ;

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {

    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (rank[a] < rank[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

int n , m ;

void solve ()
{
    cin >> n >> m ;
	set<pair<int,int>> inc;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        make_set ( i ) ;
    }

    for ( int i=0 ; i < m ; i ++ )
    {
        int t , a , b ;
        cin >> t >> a >> b ;

        if ( t == 1 )
        {
            add_edge ( a , b ) ;
			inc.insert(make_pair(a,b));
		}

        else
        {
            pair<int, int> pa = find_set(a);
			int fa = pa.first;
			int x = pa.second;

			pair<int, int> pb = find_set(b);
			int fb = pb.first;
			int y = pb.second;

			if(fa != fb){
				bool ver1 = is_bipartite ( a ) ;
				bool ver2 = is_bipartite ( b ) ;
				if ( (ver1 && ver2) ) cout << "Yes" ;
				else cout << "No" ;
			}else if(inc.find(make_pair(a,b)) != inc.end() || inc.find(make_pair(b,a)) != inc.end()){
				bool ver1 = is_bipartite ( a ) ;
				if ( ver1 ) cout << "Yes" ;
				else cout << "No" ;
			}else{
				if ( (x != y) ) cout << "Yes" ;
				else cout << "No" ;
			}			
            cout << "\n" ;
        }
    }
}

int main ()
{
    ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ; cout.tie ( 0 ) ;
    int t = 1 ;
    while ( t -- ) solve () ;

    return 0 ;
}
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
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vld vector < ld >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define pii pair < int , int >
# define pll pair < long , long >
# define pDD pair < D , D >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))
# define mod 1000000007

# define pp(n) printf("%.7f",n);
# define line cout<<"\n";

const D pie = acos(-1);
const D hpie = asin(1);
const D qpie = atan2(1,1);
const D tpie = 2*pie;

string vow = "aeiou";
double x1 , Y1 , x2 , y2 , r1 , r2 ;

bool f ( pair < double , double >  p )
{
    if ( (p.F - x2) * (p.F - x2) + (p.S - y2) * (p.S - y2) > r2 * r2 )
        R true ;
    R false ;
}

void solve ( int test_case )
{
    cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2 ;

    D t = atan2 ( y2-Y1 , x2-x1 ) ;
    pair < double , double > p1 , p2 ;

    p1.F = x1 + r1*cos ( t ) ;
    p1.S = Y1 + r1*sin ( t ) ;

    p2.F = x1 - r1*cos ( t ) ;
    p2.S = Y1 - r1*sin ( t ) ;

    if ( f ( p1 ) )
    {
        cout << "YES" ; line
        pp ( p1.F ) ;
        cout << " " ;
        pp ( p1.S )  ;

        line
    }

    else if ( f ( p2 ) )
    {
        cout << "YES" ; line
        pp ( p2.F ) ;
        cout << " " ;
        pp ( p2.S ) ;
        line
    }

    else cout << "NO\n" ;
}

int main()
{
    int t = 1;
    cin >> t;

    for ( int i=0 ; i<t ; i++ ) solve(i);
    return 0;
}

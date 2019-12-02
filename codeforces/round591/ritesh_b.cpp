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

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
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

# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";

const ld pie = 3.14159265358979 ;
const ll mod = 1e9 + 7 ;

string vow = "aeiou";

void solve ( int test_case )
{
    int n ; cin >> n ;

    vll v ( n ) ;
    for ( int i=0 ; i < n ; i++ ) cin >> v[i] , v[i] /= 100 ;

    sort ( allrev ( v ) ) ;

    ll x , a , y , b , k ;
    cin >> x >> a >> y >> b >> k ;

    // we want y > x ;

    if ( y < x ) { swap ( x , y ) ; swap ( a , b ) ; }
    ll lcm = ( a / __gcd ( a , b ) ) * b ;
    int ans = INT_MAX ;

    for ( int low = 1 , high = n ; low <= high ; )
    {
        int mid = low + high >> 1 ;
        int z = mid ;

        ll temp_sum = 0 ;
        int indx = 0 ;

        for ( int i = lcm - 1 ; i < z ; i += lcm ) temp_sum += v[indx++] * ( x + y ) ;

        for ( int i = b - 1 ; i < z ; i += b )
        {
            if ( ( i + 1 ) % lcm == 0 ) C ;
            temp_sum += v[indx++] * y ;
        }

        for ( int i = a - 1 ; i < z ; i += a )
        {
            if ( (i + 1) % lcm == 0 ) C ;
            temp_sum += v[indx++] * x ;
        }

        if ( temp_sum >= k ) ans = z , high = mid - 1 ;
        else low = mid + 1 ;
    }

    if ( ans == INT_MAX ) cout << -1 ;
    else cout << ans ;

    line

}

int main()
{
  freopen("input.txt","r",stdin);
 freopen("real.txt","w",stdout); 
  fast
    int t = 1;
    cin >> t;

    for ( int i=0 ; i < t ; i++ ) solve(i);
    return 0;
}

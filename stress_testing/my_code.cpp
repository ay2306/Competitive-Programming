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

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("my_result.txt","w",stdout);

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
    string s , r ;
    cin >> s >> r ;

    int a = s.size() , b = r.size() ;
    if ( b < a ) { cout << "Impossible\n" ; R ; }

    int h[26] = {} ;
    for ( auto i : s ) h[i - 'a'] ++ ;
    int t = 0 ;

    for ( int i=0 ; i < b ; i++ )
    {
        int indx = r[i] - 'a' ;

        if ( h[indx] )
        {
            h[indx] -- ;
            r[i] = '.' ;
            t ++ ;
        }
    }

    if ( t != a ) { cout << "Impossible\n" ; R ; }
    sort ( all ( r ) ) ;

    bool ok = false ;
    for ( int i=0 ; i < b ; i++ )
    {
        if ( r[i] == '.' ) C ;
        if ( ok ) { cout << r[i] ; C ; }
        if ( r[i] < s[0] ) { cout << r[i] ; C ; }

        if ( r[i] > s[0] )
        {
            cout << s ; ok = true ;
            cout << r[i] ; C ;
        }

        int e = 0 ;
        for ( ; e < a && s[e] == s[0] ; e ++ ) ;

        if ( e < a && s[e] < r[i] ) { cout << s << r[i] ; }
        else { cout << r[i] << s ; }

        ok = true ;
    }

    if ( !ok ) cout << s ;
    line

}

int main()
{
    FILE_READ_IN
    FILE_READ_OUT
    fast
    int t = 1;
    cin >> t;

    for ( int i=0 ; i<t ; i++ ) solve(i);
    return 0;
}

#include<bits/stdc++.h>
using namespace std ;

# define all(v) (v).begin() , (v).end()
# define allcomp(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()

# define ll long long

# define line cout << "\n" ;
# define fast ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ;

# define pii pair < int , int >
# define pll pair < ll , ll >

# define F first
# define S second

const int mod = 998'244'353 ;

const int N = 3002 ;
int n , s ;

int add ( int a , int b )
{
    a += b ;

    if ( a >= mod )
        a -= mod ;

    return a ;
}

int v[N] ;
int dp[N][N] ;

void read()
{
    cin >> n >> s ;

    for ( int i = 1 ; i <= n ; i ++ )
        cin >> v[i] ;
}

void solve ( int test_case )
{
    read () ;
    dp[0][0] = 1 ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 0 ; j <= s ; j ++ )
        {
            int &ans = dp[i][j] ;

            if ( j - v[i] >= 0 )
                ans = dp[i - 1][j - v[i]] ;

            ans = add ( ans , dp[i - 1][j] ) ;
            ans = add ( ans , dp[i - 1][j] ) ;
        }
    }

    cout << dp[n][s] ; line ;
}

int main()
{fast
    int t = 1 ;
    // cin >> t ;

    for ( int i = 1 ; i <= t ; i ++ )
    {
        solve ( i ) ;
    }

    return 0 ;
}


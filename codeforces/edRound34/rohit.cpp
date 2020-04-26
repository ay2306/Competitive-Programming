#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef long double ld ;
typedef double D ;
typedef pair <int , int> pii ;
typedef pair <ll , ll> pll ;
typedef pair <ld , ld> pld ;

#define vi vector <int>
#define vb vector <bool>
#define vll vector <ll>
#define vs vector <string>
#define vpii vector <pii>
#define vpll vector <pll>
#define vvi vector < vi >
#define vvll vector < vll >
#define vvb vector < vb >
#define pb push_back 
#define mp make_pair
#define pf push_front
#define all(v) v.begin() , v.end()
#define allrev(v) v.rbegin() , v.rend()
#define fast ios_base :: sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0)
#define F first
#define S second
#define pld pair <ld , ld>
#define vpld vector < pld >
#define MOD 1e9+7
#define infi INT_MAX
#define infll LLONG_MAX

//////////////////////////////////////////////////

void solve (int tcase){
    int n ;
    cin >> n ;
    vi a(n) ;
    vb pack(n , 0) ;
    for (int i = 0 ; i < n ; ++i){
        cin >> a[i] ;
    }
    sort(a.rbegin() , a.rend()) ;
    int cnt = n ;
    for (int i = 0 ; i < n-1 ; ++i){
        int max_pack = a[i] ;
        for (int j = i+1 ; j < n ; ++j){
            if (a[j] < max_pack && pack[j] == 0){
                pack[j] = 1 ;
                max_pack = a[j] ;
                --cnt ;
                break ;
            }
        }
    }
    cout << cnt  << "\n";
}
 
int main(){
    //freopen ("input.txt","r",stdin) ;
    //freopen ("output.txt","w",stdout) ;
    fast ;
    int t = 1 ;
//    cin >> t ;
    while (t--) 
        solve (t) ;
    return 0 ;
}
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    FAST;
    ull x,y,l,r;
    cin >> l >> r >> x >> y;
    if(y%x != 0){
        cout << "0";
        return 0;
    }
    int ans = 0;
    int n = y/x;
    for(int d = 1; d*d <= n; ++d){
        if(n%d == 0){
            int c = n/d;
            if(l <= c*x && c*x <= r && l<= d*x && d*x <= r && __gcd(c,d)==1){
                if(d*d == n)++ans;
                else ans += 2;
            }
        }
    }
    cout << ans;
    return 0;
}
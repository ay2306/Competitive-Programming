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
    M<ull,ull> m;
    ull n;
    cin >> n;
    for(ull i = 1,a; i <= n; ++i){
        cin >> a;
        m.insert(mp(a,i));
    }
    ull q;
    cin >> q;
    ull ans1 = 0;
    ull ans2 = 0;
    while(q--){
        ull a;
        cin >> a;
        ull i = m.find(a)->second;
        ans1 += i; 
        ans2 += n-i+1 ;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
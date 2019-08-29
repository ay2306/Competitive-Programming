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
    int n;
    cin >> n;
    int l = 0 ,r =0;
    for(int i=0,a,b; i < n; ++i){
        cin >> a >> b;
        l+=a;
        r+=b;
    }
    int ans = 0;
    if(l > n-l)ans+=n-l;
    else ans+=l;
    if(r > n-r)ans+=n-r;
    else ans+=r;
    cout << ans;
    return 0;
}
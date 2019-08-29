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
    int n,m;
    cin >> n >> m;
    int k = n/m;
    V<V<int> > l(m);
    V<int> arr;
    for(int i = 0,a; i < n; ++i){
        cin >> a;
        arr.pb(a);
        l[a%m].push_back(i);
    }
    ll ans = 0;
    V<P<int,int> > free;
    for(int i = 0; i < 2 * m; ++i){
        int cur = i%m;
        while(int(l[cur].size()) > k){
            int elem = l[cur].back();
            l[cur].pop_back();
            free.push_back(mp(elem,i));
        }
        while(int(l[cur].size()) < k && !free.empty()){
            int elem = free.back().first;
            int mmod = free.back().second;
            free.pop_back();
            l[cur].push_back(elem);
            arr[elem] += i-mmod;
            ans += i-mmod;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    return 0;
}
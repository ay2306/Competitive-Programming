#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
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
    MS<int> w,r;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        r.insert(a);
    }
    for(int i = 0; i < m; ++i){
        int a;
        cin >> a;
        w.insert(a);
    }
    MS<int>::IT ri = r.begin();
    MS<int>::IT wi = w.begin();
    int low = *r.rbegin();
    int high = *w.begin();
    while(low < high){
        if(low < 2 * (*r.begin())){
            ++low;
        }else{
            break;
        }
    }
    if(low >= high)cout << "-1";
    else cout << low;
    return 0;
}
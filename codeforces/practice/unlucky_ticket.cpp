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
    int n;
    cin >> n;
    string a;
    cin >> a;
    V<char> f,l;
    for(int i = 0; i < a.length()/2; ++i)f.pb(a[i]);
    for(int i = a.length()/2; i < a.length(); ++i)l.pb(a[i]);
    sort(f.begin(),f.end());
    sort(l.begin(),l.end());
    if(f[0] > l[0]){
        swap(f,l);
    }
    // cout << f.size() << " " << l.size() << endl;
    for(int i = 0; i < f.size(); ++i){
        if(f[i] >= l[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
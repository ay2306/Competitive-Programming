/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
const ll maxn = 2e5;
ll a[maxn],b[maxn];
int main(){
    FAST
    ll i;
    int n;
    cin >> n;
    for(i = 0; i < n; ++i)cin >> a[i] >> b[i];
    set<ll> s;
    for(int i = 2; i <= 1000000; ++i){
        if(a[0]%i == 0 && a[0]){
            s.insert(i);
            while(a[0] && a[0]%i == 0)a[0]/=i;
        }
        if(b[0]%i == 0 && b[0]){
            s.insert(i);
            while(b[0] && b[0]%i == 0)b[0]/=i;
        }
    }
    if(a[0] > 1)s.insert(a[0]);
    if(b[0] > 1)s.insert(b[0]);
    for(set<ll>::iterator itr = s.begin(); itr != s.end(); ++itr){
        ll no = *itr;
        int ok = 1;
        for(int i = 1; i < n; ++i){
            if(a[i]%no != 0 && b[i]%no != 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << *itr;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;

int main(){
    unordered_map<ll,ll> m;
    int n;
    cin >> n;
    ll ans = LLONG_MAX;
    PII ind;
    V<ll> arr;
    loop(i,0,n){
        ll a;
        cin >> a;
        ll k = 1;
        arr.pb(a);
        while(k*k <= a){
            if(a%k == 0){
                ll f1 = k;
                ll f2 = a/k;
                if(m.find(f1) == m.end())m[f1] = i;
                else{
                    ll p = arr[m[f1]];
                    p *= a;
                    p /= f1;
                    if(p < ans){
                        ans = p;
                        ind.F = m[f1];
                        ind.S = i;
                    }
                }
                if(arr[m[f1]] > a)m[f1] = i;
                if(f1 == f2){
                    k++;
                    continue;
                }
                if(m.find(f2) == m.end())m[f2] = i;
                else{
                    ll p = arr[m[f1]];
                    p *= a;
                    p /= f1;
                    if(p < ans){
                        ans = p;
                        ind.F = m[f1];
                        ind.S = i;
                    }
                }
                if(arr[m[f1]] > a)m[f1] = i;
            }
            ++k;
        }
    }
    cout << ind.F+1 << " " << ind.S+1;
    return 0;
}
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
#define MAXN 25
using namespace std;

int main(){
    // FILE_READ
    ll n;
    cin >> n;
    ll *arr = new ll[2*n];
    for(ll i = 0; i < 2*n; ++i)cin >> arr[i];
    if(n == 1){
        cout << "0";
        return 0;
    }
    sort(arr,arr+(2*n));
    ll area = LLONG_MAX;
    for(int i = 1; i < n; ++i)area = min(area,arr[i+n-1]-arr[i]);
    cout << min((arr[n-1]-arr[0])*(arr[(2*n)-1]-arr[n]),area*(arr[(2*n)-1]-arr[0]));
    return 0;
}
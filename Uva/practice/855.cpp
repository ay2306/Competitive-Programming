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
#define MAXN 1001000
using namespace std;

void solve(){
    ll s,a,p;
    cin >> s >> a >> p;
    V<ll> street(p);
    V<ll> av(p);
    for(int i = 0 ;i < p; ++i){
        cin >> street[i] >> av[i];
    }
    sort(av.begin(),av.end());
    sort(street.begin(),street.end());
    if(p%2 == 1){
        cout << "(Street: " << street[p/2] << ", Avenue: " << av[p/2] << ")\n";
    }else{
        cout << "(Street: " << street[(p-1)/2] << ", Avenue: " << av[(p-1)/2] << ")\n";
        // cout << "(Street: " << ((street[p/2]+street[(p-1)/2])/2) << ", Avenue: " << ((av[p/2]+av[(p-1)/2])/2) << ")\n";
    }
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
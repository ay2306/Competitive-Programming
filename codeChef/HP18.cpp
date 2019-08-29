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
#define MAXN 25
using namespace std;

void solve(){
    int n;
    ll a,b;
    cin >> n >> a >> b;
    V<int> s,y,z;
    int A=0,B=0,C=0;
    for(int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        if(x%b == 0 && x%a == 0){C++;s.pb(x);}
        else if(x%a == 0){A++;y.pb(x);}
        else if(x%b == 0){B++;z.pb(x);}
    }
    cout << "common: ";
    for(auto i : s)cout << i << " ";
    cout << endl;
    cout << "A: ";
    for(auto i : y)cout << i << " ";
    cout << endl;
    cout << "B: ";
    for(auto i : z)cout << i << " ";
    cout << endl;
    cout << A << " " << B << " " << C << "\n";
    B-=(C%2);
    if(A > B)cout << "BOB\n";
    else cout << "ALICE\n";
    
}

int main(){
    FILE_READ_IN
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
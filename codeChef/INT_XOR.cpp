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
#define PUU pair<un<<signed long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset<<
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

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        V<ll> arr(n+1);
        ll a;
        ll res;
        cout << "1 1 2 3\n";
        fflush(stdout);
        cin >> a;
        cout << "1 1 2 4\n";
        fflush(stdout);
        cin >> res;
        a = (a^res);
        cout << "1 1 3 4\n";
        fflush(stdout);
        cin >> res;
        arr[1] =  (res^a);
        cout << "1 2 3 4\n";
        fflush(stdout);
        cin >> res;
        arr[2] =  (res^a);
        for(int i = 5; i <= n; ++i){
            cout << "1 3 4 " << i << "\n";
            fflush(stdout);
            cin >> res;
            arr[i] = (a^res); 
        }
        cout << "1 2 3 1\n";
        fflush(stdout);
        cin >> res;
        arr[3] = (res^arr[1]^arr[2]);
        cout << "1 2 4 1\n";
        fflush(stdout);
        cin >> res;
        arr[4] = (res^arr[1]^arr[2]);
        cout << "2 ";
        for(int i = 1; i <= n; ++i)cout << arr[i] << " ";
        cout << "\n";
        fflush(stdout);
    }
}
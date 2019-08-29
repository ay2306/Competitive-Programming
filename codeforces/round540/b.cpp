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
    int n;
    cin >> n;
    V<ll> arr(n+1);
    V<ll> e(n+1,0);
    V<ll> o(n+1,0);
    loop(i,1,n+1){
        cin >> arr[i];
        e[i] = e[i-1];
        o[i] = o[i-1];
        if(i%2)o[i]+=arr[i];
        else e[i]+=arr[i];
    }
    // for(auto i: e){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto i: o){
    //     cout << i << " ";
    // }
    // cout << endl;
    int ans = 0;
    loop(i,1,n+1){
        ll even = e[i-1] + o[n] - o[i];
        ll odd = o[i-1] + e[n] - e[i];
        // cout << even << " " << odd << "\n";
        if(even == odd){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
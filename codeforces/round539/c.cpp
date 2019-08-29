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
    FAST
    int n;
    cin >> n;
    V<ll> a(n);
    int ans = 0;
    unordered_map<ll,ll > odd,even;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    a[1] = a[0]^a[1];
    even[a[0]] = 1;
    odd[a[1]] = 1;
    for(int i = 2; i < n; ++i){
        if(i%2){
            a[i] =  (a[i]^a[i-1]);
            if(a[i] == 0){
                ans++;
            }
            ans+=odd[a[i]];
            odd[a[i]]++;
        }else{
            a[i] =  (a[i]^a[i-1]);
            ans+=even[a[i]];
            even[a[i]]++;
        }
    }
    // for(auto i: a){
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << ans;
    return 0;
}
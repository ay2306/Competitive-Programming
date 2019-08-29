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
    int n;
    ll lim;
    cin >> n >> lim;
    int *arr = new int[n];
    ll *array = new ll[n];
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        array[i] = a;
        arr[i] = a%2;
    }
    V<ll> v;
    ll k = arr[0];
    int o=0,e=0;
    for(int i = 0; i < n; ++i){
        if(arr[i])e++;
        else o++;
        if(e==o && i+1 < n){
            v.pb(abs(array[i]-array[i+1]));
        }
    }
    // cout << endl;
    sort(v.begin(),v.end());
    ll sum = 0;
    k = 0;
    // for(int i = 0; i < v.size(); ++i){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // auto itr = v.begin();
    for(int i = 0; i < v.size(); ++i){
        sum+=v[i];
        if(sum > lim)break;
        ++k;
    }
    cout << k;
    return 0;
}
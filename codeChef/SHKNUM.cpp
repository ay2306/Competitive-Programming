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
#define MAXN 1000000000000
using namespace std;
vector<ll> arr;
ll abso(ll a){
    if(a < 0)a*=-1;
    return a;
}

int bs(ll a){
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = high+low;
        mid/=2;
        if(arr[mid] == a)return mid;
        if(mid > 0 && arr[mid] > a && arr[mid-1] < a)return mid-1;
        if(mid+1 < arr.size() && arr[mid] < a && arr[mid+1] > a)return mid;
        if(arr[mid] > a)high=mid-1;
        else low = mid+1;
    }
}
int main(){
    FAST
    arr.pb(0);
    FILE_READ;
    vector<ll> v1,v2;
    set<ll> s;
    int i = 0;
    while(1){
        ll k = 1;
        if((k << i) > MAXN){
            break;
        }
        v1.pb((k << i));
        v2.pb((k << i));
        ++i;
    }
    // cout << i << endl;
    for(int j = 0; j < v1.size(); ++j){
        for(int i = 0; i < v2.size(); ++i){
            if(i == j)continue;
            s.insert(v2[i]+v1[j]);
        }
    }
    for(set<ll>::IT itr = s.begin(); itr != s.end(); ++itr){
        // cout << *itr << " ";
        arr.pb(*itr);
    }
    arr.pb(LLONG_MAX);
    // cout << endl;
    // cout << arr.size();
    cout << "arr[] = {";
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << ",";
    }
    cout << "};";
    int t;
    
    // cin >> t;
    // while(t--){
    //     ll n;
    //     cin >> n;
    //     if(n == 1){
    //         cout << "2\n";
    //         continue;
    //     }
    //     ll ans = n;
    //     int i = 0;
    //     int mid = bs(n);
    //     // cout << arr[mid] << " MID\n";
    //     // cout << arr[mid+1] << " MID+1\n";
    //     // cout << arr[mid-1] << " MID-1\n";
    //     if(arr[mid] == n || arr[mid-1] == n || arr[mid+1]==n)ans = 0;
    //     else{
    //         ans = min(abso(n-arr[mid]),abso(n-arr[mid-1]));
    //         ans = min(ans,abso(n-arr[mid+1]));
    //     }
    //     cout << ans << endl;
    // }
return 0;
}
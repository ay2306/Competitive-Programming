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
    ll n,k,s;
    cin >> n >> k >> s;
    ll last = 1;
    ll tmpvar = k;
    ll sum = 0;
    V<ll> arr;
    if((n-1)*k < s || k > s){
        cout << "NO";
        return 0;
    }
    while(sum+n-1+k-1 < s && k){
        sum+=n-1;
        k--;
        if(last == 1){
            last = n;
        }else{
            last = 1;
        }
        arr.pb(last);
    }
    ll b = s - sum - k + 1;
    if(last == 1){
        k--;
        last = 1+b;
        arr.pb(last);
    }else{
        k--;
        last = n-b;
        arr.pb(last);
    }
    while(k){
        if(last == n)last--;
        else last++;
        arr.pb(last);
        k--;
    }
    sum = arr[0]-1;
    cout << "YES\n";
    for(int i = 0; i < arr.size(); ++i){
        if(i)sum+=(abs(arr[i]-arr[i-1]));
        cout << arr[i] << " ";
    }
    // cout << endl << arr.size() << " " << sum << endl;
    return 0;
}
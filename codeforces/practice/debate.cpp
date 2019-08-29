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

int main(){
    int n;
    cin >> n;
    deque<ll> arr[4];
    while(n--){
        string a;
        ll k;
        cin >> a >> k;
        if(a == "00")arr[0].pb(k);
        if(a == "01")arr[1].pb(k);
        if(a == "10")arr[2].pb(k);
        if(a == "11")arr[3].pb(k);
    }
    ll ans = 0;
    int t = 0;
    loop(i,0,4)sort(arr[i].begin(),arr[i].end());
    while(arr[3].size()){
        ans+=arr[3].back();
        arr[3].pop_back();
        t++;
    }
    int a = min(arr[1].size(),arr[2].size());
    while(arr[1].size() && arr[2].size()){
        ans+=arr[1].back();
        ans+=arr[2].back();
        arr[1].pop_back();
        arr[2].pop_back();
        t+=2;
    }
    while(arr[1].size()){
        arr[0].pb(arr[1].back());
        arr[1].pop_back();
    }
    while(arr[2].size()){
        arr[0].pb(arr[2].back());
        arr[2].pop_back();
    }
    sort(arr[0].begin(),arr[0].end());
    while(arr[0].size()){
        if(a*2 >= t)break;
        ans+=arr[0].back();
        arr[0].pop_back();
        t++;
        a++;
    }
    cout << ans;
    return 0;
}
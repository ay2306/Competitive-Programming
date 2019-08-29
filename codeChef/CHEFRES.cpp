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

bool lieIn(PLL a, int t){
    return (a.first <= t && a.second > t);
}

ll BinarySearch(PLL *arr, int n, ll t){
    if(t >= arr[n-1].second)return -1;
    if(t <= arr[0].first)return arr[0].first - t;
    int l = 0;
    int r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(lieIn(arr[mid],t))return 0;
        if(mid != 0 && arr[mid-1].second <= t && arr[mid].first > t)return arr[mid].first - t;
        if(mid != n-1 && arr[mid].second <= t && arr[mid+1].first > t)return arr[mid+1].first - t;
        if(arr[mid].first < t)l = mid+1;
        else r = mid-1;
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    PLL *arr = new PLL[n];
    loop(i,0,n){
        int l,r;
        cin >> l >> r;
        arr[i] = mp(l,r);
    }
    sort(arr,arr+n);
    while(m--){
        ll a;
        cin >> a;
        cout << BinarySearch(arr,n,a) << endl;
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
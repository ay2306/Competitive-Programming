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

int bs(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;
    if(arr[0] < x)return 0;
    if(arr[high] > x)return arr.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x)return mid;
        if(mid+1 < arr.size() && arr[mid] > x && arr[mid+1] < x)return mid+1;
        if(mid-1 >= 0 && arr[mid-1] > x && arr[mid] < x)return mid;
        if(arr[mid] > x)low = mid+1;
        else high = mid-1;
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    unordered_map<int,int> m;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        m[a]++;
        if(m[a] == 1)arr.pb(a);
    }
    ll ans = 0;
    vector<pair<int,int> > p;
    for(auto i: m){
        p.pb(mp(i.second,i.first));
    }
    sort(p.begin(),p.end(),greater<PII>());
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i = 0; i < arr.size(); ++i){
        // printf("p[%d] = (%d,%d) and arr[%d] = (%d,%d)\n",0,p[0].first,p[0].second,i,arr[i],m[arr[i]]);
        for(int j = 0; j < p.size() && p[j].first >= arr[i]; ++j){
            if(m[arr[i]] >= p[j].second){
                ans++;
                // printf("p[%d] = (%d,%d) and arr[%d] = (%d,%d)\n",j,p[j].first,p[j].second,i,arr[i],m[arr[i]]);
                // cout << arr[i] << " " << arr[j] << "\n";
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
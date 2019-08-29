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
V<PII> arr;

int bs(int a){
    int low = 0;
    int high = arr.size()-1;
    if(a < arr[low].first)return -1;
    if(a >= arr[high].first)return high;
    while(low <= high){
        int mid = (low+high)/2;
        if(a == arr[mid].first)return mid;
        else if(mid != 0 && a < arr[mid-1].first && a > arr[mid].first)return mid-1;
        else if(mid != arr.size()-1 && a < arr[mid].first && a > arr[mid+1].first)return mid;
        else if(a < arr[mid].first)high = mid-1;
        else low = mid+1;
    }
}

void solve(){
    int n;
    cin >> n;
    arr = V<PII>(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    int q;
    V<int> a(n);
    a[0] = arr[0].second;
    for(int i = 1; i < n; ++i){
        a[i] = a[i-1]+arr[i].second;
    }
    cin >> q;
    while(q--){
        int d,req;
        cin >> d >> req;
        int s = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i].first > d)break;
            s+=arr[i].second;
        }
        if(s >= req)cout << "Go Camp\n";
        else cout << "Go Sleep\n";
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
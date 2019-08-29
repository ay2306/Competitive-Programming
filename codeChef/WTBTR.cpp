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
#define ll double
#define P pair
#define PLL pair<double,double>
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
const ll inf = 1e9;

int binarysearch(V<ll> &arr,ll val){
    if(val < *arr.begin())return *arr.begin();
    if(val == *arr.begin())return arr[1];
    if(val > *arr.rbegin())return *arr.rbegin();
    if(val == *arr.rbegin())return arr[arr.size()-2];
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == val){
            if(abs(val-arr[mid-1]) < abs(arr[mid+1]-val))return arr[mid-1];
            return arr[mid+1];
        }else if(arr[mid] < val){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
}

void solvesmall(V<PLL> &arr){
    double ans = LLONG_MAX;
    loop(i,0,arr.size()){
        loop(j,i+1,arr.size()){
            double x = arr[i].F + arr[j].F;
            double y = arr[i].S + arr[j].S;
            x/=2;
            y/=2;
            double l1 = -1*(x+y);
            double l2 = y-x;
            ans = min(abs(arr[i].F + arr[i].S + l1),ans);
            ans = min(abs(arr[i].F - arr[i].S + l2),ans);
        }
    }
    printf("%.10f\n",ans);
}

void solve(){
    int n;
    scanf("%d",&n);
    V<PLL> arr(n);
    unordered_map<ll,int> m1;
    unordered_map<ll,int> m2;
    V<ll> c1;
    V<ll> c2;
    bool zero = false;
    loop(i,0,n){
        scanf("%lf%lf",&arr[i].F,&arr[i].S);
        if(m1.find(-1*(arr[i].F + arr[i].S)) != m1.end())zero =true;
        m1[-1*(arr[i].F + arr[i].S)]++;
        if(m2.find(arr[i].S - arr[i].F) != m2.end())zero = true;
        m2[arr[i].S - arr[i].F];
        c1.pb(arr[i].F + arr[i].S);
        c2.pb(arr[i].F - arr[i].S);
    }
    if(zero){
        printf("0.0000000000\n");
        return;
    }
    if(n <= 500){
        solvesmall(arr);
        return;
    }
    sort(c1.begin(),c1.end());
    sort(c2.begin(),c2.end());
    double ans = LLONG_MAX;
    loop(i,0,n){
        ll v1 = binarysearch(c1,(arr[i].F + arr[i].S));
        ll v2 = binarysearch(c2,arr[i].F - arr[i].S);
        // cout << " Two values = " << v1 << " " << v2 << "\n";
        ll k = min(abs(arr[i].F+arr[i].S - v1),abs(arr[i].F-arr[i].S - v2));
        ans = min(double(k),ans);
    }
    printf("%.10lf\n",ans/2);
}

int main(){
    // FAST
    int t = 1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
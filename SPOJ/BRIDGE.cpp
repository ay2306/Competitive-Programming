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

vector<int> q;
int bs(int num){
    int low = 0;
    int high = q.size()-1;
    if(q[high] <= num)return q.size();
    if(q[low] >= num)return 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(q[mid] == num)return mid;
        if(mid + 1 < q.size() && q[mid+1] >= num && q[mid] < num)return mid+1;
        if(mid -1 >= 0 && q[mid] >= num && q[mid-1] < num)return mid;
        if(q[mid] > num)high = mid-1;
        else low = mid+1;
    }
}

void solve(){
    q.clear();
    int n;
    cin >> n;
    PII *arr = new PII[n];
    int *dp = new int[n];
    loop(i,0,n){
        int a;
        cin >> a;
        arr[i] = mp(a,0);
    }
    loop(i,0,n){
        int a;
        cin >> a;
        arr[i].second = a;
    }
    sort(arr,arr+n);
    // for(int i = 0; i < n; ++i){
    //     printf("(%d, %d)\n",arr[i].first,arr[i].second);
    // }
    // q.pb(arr[0].second);
    // loop(i,1,n){
    //     int k = bs(arr[i].second);
    //     if(k == q.size())q.pb(arr[i].second);
    //     else q[k] = arr[i].second;
    // }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[i].second >= arr[j].second)dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i = 0; i < n; ++i){
        ans = max(ans,dp[i]);
    }
    // for(auto i: q)cout << i << " ";
    // cout << "\n";
    // int b = q.size();
    // cout << q.size() << "\n";
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
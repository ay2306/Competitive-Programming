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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     int *dp = new int[n];
//     for(int i = 0; i < n; ++i){
//         cin >> arr[i];
//     }    
//     for(int i = 0; i < n; ++i){
//         dp[i] = 1;
//         for(int j = 0; j < i; ++j){
//             if(arr[j] < arr[i]){
//                 dp[i] = max(dp[i],dp[j]+1);
//             }
//         }
//     }
//    return 0;
// }

// O(nlogn) approach

int bsPos(int *arr, int n, int val){
    if(arr[1] > val)return 1;
    if(arr[n] < val)return n;
    int low = 1;
    int high = n;
    while(low < high){
        int mid = low + (high-low)/2;
        if(arr[mid] == val)return 0;
        if(arr[mid] > val && arr[mid-1] < val)return mid;
        if(arr[mid] < val && arr[mid+1] > val)return mid+1;
        if(arr[mid] > val)high = mid-1;
        else low = mid+1;
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int *I = new int[n+1];
    // memset(I,INT_MAX,sizeof(I));
    I[0] = INT_MIN;
    int *L = new int[n];
    for(int j = 0; j <= n; ++j){
        if(!j)continue;
        else I[j] = INT_MAX;
        // if(I[j] == INT_MAX)cout << "i ";
        // else if(I[j] == INT_MIN)cout << "-i ";
        // else cout << I[j] << " ";
    }
    // cout << endl;
    int ans = 1;
    for(int i = 0; i < n; ++i){
        int k = bsPos(I,n,arr[i]);
        if(k!=0){
            I[k] = arr[i];
            L[i] = k;
        }
        ans = max(k,ans);
        for(int j = 0; j < n; ++j){
            // if(I[j] == INT_MAX)cout << "i ";
            // else if(I[j] == INT_MIN)cout << "-i ";
            // else cout << I[j] << " ";
            // cout << L[j] << " ";
        }
        // cout << endl;
    }
    cout << ans;
    return 0;
}
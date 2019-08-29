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
#define MAXN 1001000
using namespace std;
class Solution{
int *arr;
int ans;
int n;
public:
    Solution(){
        ans = INT_MAX;
        cin >> n;
        arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        for(int i = 0; i < 100; ++i){
            // cout << i << " " << findDistance(i) << endl;
            ans = min(findDistance(i),ans);
        }
        cout << ans << endl;
    }
    int findDistance(int k){
        int ans = 0;
        int ind = 0;
        for(ind = 0; ind < n; ++ind){
            if(arr[ind] > k)break;
        }
        if(ind >= n-1){
            ans += 2*abs(arr[n-1]-k);
            for(int i = n-2; i >=0 ; --i){
                ans += 2*abs(arr[i]-arr[i+1]);
            }
            return ans;
        }
        if(ind == 0){
            ans += 2*abs(arr[0]-k);
            for(int i = 1; i < n ; ++i){
                ans += 2*abs(arr[i]-arr[i-1]);
            }
            return ans;
        }
        ans+=(2*abs(arr[ind-1]-k));
        for(int i = ind-2; i >= 0; --i){
                ans += 2*abs(arr[i]-arr[i+1]);
        }
        ans+=(2*abs(arr[ind+1]-k));
        for(int i = ind+2; i < n; ++i){
                ans += 2*abs(arr[i]-arr[i-1]);
        }
        return ans;
    }

};

int main(){
    int t;
    cin >> t;
    while(t--){
        Solution t;
    }
    return 0;
}
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

int main(){
    int n;
    cin >> n;
    int W=0;
    int *arr = new int[n+1];
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        W+=arr[i];
    }
    int *dp = new int[2*W + 1];
    init(dp,0);
    dp[0] = 1;
    for(int k = 1; k<=n; ++k){
        for(int x = W; x >= 0; --x){
            if(dp[x] == 1)dp[x+arr[k]]=1;
        }
    }
    for(int i = 0; i <= W; ++i){
        if(dp[i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
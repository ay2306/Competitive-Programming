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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
int dp[201][201];
int ans;
int CalculateMinutes(int a, int b, int m){
    if(a <= 0 || b <= 0){ 
        return 0;
    }
    // if(dp[a][b]!=0){
    //     return m+dp[a][b];
    // }
    // if(a >= 100){
    //     dp[a][b] = CalculateMinutes(a-2,b+1,m+1);
    //     return dp[a][b];
    // }
    // if(b >= 100){
    //     dp[a][b] = CalculateMinutes(a+1,b-1,m+1);
    //     return dp[a][b];
    // }
    // dp[a][b] = max(CalculateMinutes(a-2,b+1,m+1),CalculateMinutes(a+1,b-2,m+1));
    // return dp[a][b];
     if(dp[a][b]!=0)
    return dp[a][b];
    int op1 = 0;
    int op2 = 0;
    if(b<101)op1 = 1+ CalculateMinutes(a-2,b+1,m+1);
    if(a<101)op2 = 1+  CalculateMinutes(a+1,b-2,m+1);
    dp[a][b] = max(op1,op2);
    return dp[a][b];
}

int main(){
    int a,b;
    cin >> a >> b;
    if(a < 2 && b < 2){
        cout << "0";
        return 0;
    }
    cout << CalculateMinutes(a,b,0);
    // cout << ans;
    return 0;
}
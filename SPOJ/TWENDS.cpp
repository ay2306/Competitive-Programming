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
int arr[1010];
int n;
int dp[1010][1010];
int greedy(){
    int i = 0;
    int j = n-1;
    int c = 1;
    int s = 0;
    while(i <= j){
        if(arr[i] >= arr[j]){
            if(c)s+=arr[i];
            i++;
        }else{
            if(c)s+=arr[j];
            j--;
        }
        c = 1-c;
    }
    return s;
}

int rec(int i, int j){
    if(i == j)return arr[i];
    if(i > j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(arr[i+1] < arr[j])dp[i][j] = arr[i] + rec(i+1,j-1);
    else dp[i][j] = arr[i] + rec(i+2,j);
    if(arr[i] > arr[j-1])dp[i][j] = max(dp[i][j], arr[j] + rec(i+1,j-1));
    else dp[i][j] = max(dp[i][j],arr[j] + rec(i,j-2));
    return dp[i][j];
}
int c = 1;
int main(){
    while(1){
        memset(dp,-1,sizeof(dp));
        cin >> n;
        if(n == 0)break;
        int s= 0;
        loop(i,0,n){
            cin >> arr[i];
            s+=arr[i];
        }
        int g = greedy();
        int d = rec(0,n-1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",c++,2*d-s);
    }
    return 0;
}
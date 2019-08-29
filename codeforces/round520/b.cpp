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

int main(){
    int n;
    cin >> n;
    V<int> arr(n+1);
    loop(i,0,n)cin >> arr[i];
    int ans = 0;
    int c = 0;
    arr[n] = 1000;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            bool f = true;
            for(int k = i; k < j; ++k){
                if(arr[k]+1 != arr[k+1]){
                    f = false;
                    break;
                }
            }
            if(f){
                if(arr[i] == 1 || arr[j] == 1000){
                    ans = max(ans,j-i);
                }else{
                    ans = max(ans,j-i-1);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
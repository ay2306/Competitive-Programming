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

int arr[1010][1010];
int pos[1010];
int n;

int main(){
    // FAST
    cin >> n;
    loop(i,0,n)pos[i] = 1;
    for(int i =0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char a;
            cin >> a;
            if(a == 'T')arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 1 && arr[j][i] == 0){
                pos[i] = 0;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int k = 1;
        if(!pos[i])continue;
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 1)k*=pos[j];
        }
        if(k){
            k = 0;
            for(int j = 0; j < n; ++j){
                k+=arr[i][j];
            }
        }
        ans = max(k,ans);
    }
    cout << ans;
    return 0;
}
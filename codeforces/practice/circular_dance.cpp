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

bool check(PII a, int b){
    if(a.F == b || a.S == b)return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    V<PII> arr(n+1);
    V<bool> visited(n+1,false);
    loop(i,1,n+1){
        int a,b;
        cin >> a >> b;
        arr[i] = mp(a,b);
    }
    visited[1] = true;
    V<int> ans(n+1);
    ans[1] = 1;
    for(int i = 2; i <= n; ++i){
        PII a = arr[ans[i-1]];
        if(check(arr[a.first],a.second) && !visited[a.first]){
            ans[i] = a.first;
            visited[a.first] = true;
        
        }else{
            ans[i] = a.second;
            visited[a.second] = true;
        }
    }
    for(int i = 1; i <= n; ++i)cout << ans[i] << " ";
    return 0;
}
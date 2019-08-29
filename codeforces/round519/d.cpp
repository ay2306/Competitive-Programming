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

int main(){
    int n,m;
    cin >> n >> m;
    vector<unordered_map<int,int> > arr (m,unordered_map<int,int>());
    vector<int> a(n);
    loop(i,0,n)cin >> a[i];
    loop(i,0,n)arr[0][i] = a[i];
    for(int i = 1; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int b;
            cin >> b;
            arr[i][b] = j;
        }
    }
    vector<ll> ans(n);
    ans[0] = 1;
    for(int i = 1; i < n; ++i){
        int t = ans[i-1];
        for(int j = 1; j < m; ++j){
            if(1 != arr[j][a[i]] - arr[j][a[i-1]]){
                t = 0;
                break;
            }
        }
        if(t == 0){
            ans[i] = 1;
        }else{
            ans[i] = 1+ans[i-1];
        }
    }
    ll sum = 0;
    for(auto i: ans){
        // cout << i << " " ;
        sum+=i;
    }
    // cout << "\n";
    cout << sum;
    return 0;
}
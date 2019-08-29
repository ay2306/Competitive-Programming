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

void solve(){
    int n;
    cin >> n;
    V<ll> arr(n+1);
    loop(i,1,n+1)cin >> arr[i];
    map<ll,int> m;
    loop(i,1,n+1){
        m[arr[i]]++;
        if(m[arr[i]] > n/2){
            cout << "No\n";
            return;
        }
    }
    V<ll> ans(n+1);
    loop(i,1,n+1){
        bool pos = false;
        for(auto j:m){
            cout << j.first << " " << arr[i] << "\n";
            if(j.first != arr[i]){
                ans[i] = j.first;
                pos = true;
                break;
            }
        }
        m[ans[i]]--;
        if(m[ans[i]]==0)m.erase(ans[i]);
    }
    // loop(i,1,n+1)cout << ans[i] << " ";
    cout << "Yes\n";
    loop(i,1,n+1)cout << ans[i] << " ";
    cout << "\n";
    return ;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
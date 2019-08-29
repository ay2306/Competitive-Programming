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
    FILE_READ
    ll ans = 0;
    ll last = 0;
    ll n,m;
    cin >> n >> m;
    ll *arr = new ll[n];
    loop(i,0,n){
        ans = 0;
        cin >> arr[i];
        if(last != 0){
            if(arr[i] < last){
                last-=arr[i];
                arr[i] = 0;
            }else{
                arr[i]-=last;
                ans++;
                last = 0;
            }
        }
        if(arr[i]){
            last = m - arr[i]%m;
            if(last == m)last = 0;
            ans+=(arr[i]/m);
        }
        cout << ans << " ";
    }
    return 0;
}   
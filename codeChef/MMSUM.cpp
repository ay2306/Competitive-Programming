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

void solve(){
    int n;
    cin >> n;
    ll *arr = new ll[n];
    loop(i,0,n)cin >> arr[i];
    ll max_so_far = 0;
    ll max_till_here = 0;
    ll m = LLONG_MAX;
    bool one_pos = false;
    ll min_so_far = LLONG_MAX;
    loop(i,0,n){
        if(arr[i] >= 0)one_pos = true;
        max_till_here += arr[i];
        m = min(m,arr[i]);
        if(max_till_here < 0){
            max_till_here = 0;
            m = LLONG_MAX;            
        }else{
            if(max_till_here > max_so_far){
                max_so_far = max_till_here;
                min_so_far = m;
            }
        }
    }
    if(!one_pos){
        ll k = LLONG_MIN;
        loop(i,0,n)k=max(arr[i],k);
        cout << k << endl;
        return ;
    }
    if(min_so_far < 0)cout << max_so_far - min_so_far << endl;
    else cout << max_so_far << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
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
using namespace std;

const ll maxn = 1e5;

bool comp(P<PII,int>  a, P<PII,int>  b){
    if(a.F.F < b.F.F)return true;
    if(a.F.F > b.F.F)return false;
    if(a.F.S < b.F.S)return true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    V<P<PII,int> > arr(n);
    loop(i,0,n){
        int a,b;
        cin >> a >> b;
        arr[i] = mp(mp(a,b),i);
    }
    sort(arr.begin(),arr.end());
    V<int> ans(n,2);
    ans[arr[0].S] = 1;
    int l = arr[0].F.F;
    int r = arr[0].F.S;
    loop(i,1,n){
        if(arr[i].F.F <= r){
            l = min(arr[i].F.F,l);
            r = max(arr[i].F.S,r);
            ans[arr[i].S] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(ans[i] == 2){
            for(auto j: ans){
                cout << j << " ";
            }
            cout << "\n";
            return ;
        }
    }
    cout << "-1\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
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
#define PLLL pair<pair<long,long>,long>
using namespace std;

int arr[100100];
int diff[100100];

inline void update(ll l, ll r, ll x){
    diff[l]+=x;
    diff[r+1]-=x;
    // printf("Update for range (%lld,%lld) by %lld\n",l,r,x);
}

void solve(){
    int n,k;
    cin >> n >> k;
    memset(diff,0,sizeof(diff));
    // arr = V<ll> (n+2,0);
    // diff = V<ll> (n+2,0);
    loop(i,1,n+1){
        cin >> arr[i];
    }
    for(int i = n; i >= 1; --i){
        int a = arr[i];
        int current = 1;
        int sq = sqrt(a);
        int j;
        for(j = 1; j <= sq; ++j){
            if(i -j +1  < 1)break;
            update(i-j+1,i-j+1,a/j);        
        }
        int p = a/j;
        while(j <= a){
            int k = p;
            if(k == 0)break;
            k = a/k;
            int st = j;
            int en = k;
            if(i-st+1 < 1)break;
            update(max(1,i-en+1),i-st+1,p);
            if(max(1,i-en+1) <= 1LL)break;
            j = k+1;
            p--;
            // cout << en << "\n";
        }
    }
    arr[1] = diff[1];
    for(int i = 2; i <= n; ++i){
        arr[i] = diff[i] + arr[i-1];
    }    
    for(int i = 1; i <= n; ++i){
        if(arr[i] <= k){
            cout << i << "\n";
            return;
        }
    }
    cout << n+1 << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
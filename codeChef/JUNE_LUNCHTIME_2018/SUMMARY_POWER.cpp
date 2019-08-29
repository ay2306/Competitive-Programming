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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    string a;
    cin >> a;
    int *arr = new int[a.length()];
    arr[0] = 0;
    for(int i = 1; i < a.length(); ++i){
        if(a[i] == a[i-1])arr[i] = 0;
        else arr[i]=1;
    }
    if(2*k < n+1){
        ll ans = 0;
        for(int i = 0; i < k; ++i){
            // cout << a[i] << " arr[" << i << "] = " << arr[i]  << " i = " << i << endl;
            ans+=(arr[i]*i);
        }
        for(int i = n-1, l = 1; l <= k; --i,++l){
            // cout << a[i] << " arr[" << i << "] = " << arr[i] << " l = " << l << endl;
            ans+=(l*arr[i]);
        }
        for(int i = k; i < n-k; ++i){
            // cout << a[i] << " arr[" << i << "] = " << arr[i] << " k = " << k << endl;
            ans+=(k*arr[i]);
        }
        cout << ans << endl;
        return ;
    }else{
        // cout << "OVERLAPPING SITUATION\n";
        int q = n-k;
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            int j = min(i,q);
            j = min(j,n-i);
            // cout << a[i] << " arr[" << i << "] = " << arr[i] << " j = " << j << endl;
            ans+=(j*arr[i]);
        }
        cout << ans << endl;
    }
}
int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
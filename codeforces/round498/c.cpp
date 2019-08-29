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

int main(){
    FILE_READ
    int n;
    cin >> n;
    ll *arr = new ll[n];
    ll *a = new ll[n];
    ll *b = new ll[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    a[0] = arr[0];
    ll ans = -1;
    b[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; --i){
        b[i] = arr[i] + b[i+1];
    }
    for(int i = 1; i < n; ++i){
        a[i] = arr[i] + a[i-1];
    }
    for(int i = 0; i < n; ++i){
        cout << "i = " <<  a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; ++i){
        cout << "i = " <<  b[i] << " ";
    }
    cout << endl;
    int j = n-1;
    for(int i = 0; i < n; ++i){
        while(b[j] < a[i]){
            j--;
        }   
        if(b[j] == a[i] && i < j){
            ans = max(ans,a[i]);
        }
    }
    if(ans == -1)cout << "0";
    else cout << ans;
    return 0;
}
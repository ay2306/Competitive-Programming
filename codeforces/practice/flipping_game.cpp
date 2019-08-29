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

using namespace std;

// int main(){
//     int n,one=0,zero=0;
//     cin >> n;
//     int *arr = new int[n];
//     for(int i = 0; i < n; ++i){
//         cin >> arr[i];
//         if(arr[i])one++;
//         else zero++;
//     }
//     int mx = zero;
//     // cout << "ONE = " << one;
//     // cout << "\nZERO = " << zero << endl;
//     if(zero == 0){
//         cout << n-1;
//         return 0;
//     }
//     for(int i = 0; i < n && zero; ++i){
//         for(int j = i; j < n; ++j){
//             int so=0;
//             int sz=0;
//             int ro;
//             for(int k = i; k <= j; ++k){
//                 if(arr[k])so++;
//                 else sz++;
//             }    
//             ro = one-so;
//             // cout << so << "  " << sz << "  " << one-so+sz << endl;
//             if(ro+sz > mx && sz){
//                 mx = ro+sz;
//                 // cout << i << "  " << j << "  " << mx << endl;
//             }
//         }
//     }
//     cout << mx;
//     return 0;
// }
int main(){
    int a,n,me=0,mx=INT_MIN,l=-1,o=0,z=0;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a == 1){o++;arr[i]=-1;}
        else {z++;arr[i]=1;}
        me+=arr[i];
        me = max(me,0);
        mx = max(mx,me);
    }
    if(z == 0)cout << n-1;
    else cout << o + mx;
    return 0;
}
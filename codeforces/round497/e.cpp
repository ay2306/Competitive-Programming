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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    // ull x_max = LLONG_MAX;
    // ull y_max = LLONG_MAX;
    // ull x_min = 0;
    // ull y_min = 0;
    // ull ans = LLONG_MAX;
    // ull x,y;
    // while(ans!=0){
    //     x = x_min + (x_max-x_min)/2;
    //     y = y_min + (y_max-y_min)/2;
    //     cout << x << " " << y << endl;
    //     cin >> ans;
    //     if(ans == 1){
    //         x_min = x;
    //     }
    //     if(ans == 2){
    //         y_min == y;
    //     }
    //     if(ans == 3){
    //         cout << x << " 0\n";
    //         cin >> ans;
    //         if(ans == )
    //     }
    // }
    int n;
    cin >> n;
    int a[n],b[n];int x;
    cin >> a[0] >> b[0];
    b[0] = max(a[0],b[0]);
    for(int i = 1; i < n; ++i){
        cin >> a[i] >> b[i];
        x = max(a[i],b[i]);
        if(x > b[i-1]){
            b[i] = min(a[i],b[i]);
        }else{
            b[i] = x;
        }
    }
    int ans = 1;
    
    return 0;
}
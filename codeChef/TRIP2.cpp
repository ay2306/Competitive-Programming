#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n,k;
int getNumber(int a){
    if(a == 0)return k;
    return a;
}
void solve(){
    cin >> n >> k;
    V<int> arr(n+2,-1);
    V<int> non;
    loop(i,1,n+1){
        cin >> arr[i];
        if(arr[i] != -1)non.pb(i);
    }
    if(n == 1){
        if(arr[0]==-1)cout << "YES\n1\n";
        else cout << "YES\n" << arr[0] << "\n";
        return;
    }
    // if(non.size() == n){
    //     cout << "YES\n";
    //     loop(i,0,n){
    //         cout << i%2+1<< " ";
    //     }
    //     cout << "\n";
    //     return;
    // }
    if(non.size() == 0){
        loop(i,0,n){
            cout << i%2 + 1 << " ";
        }
        cout << "\n";
        return;
    }
    int lst = non[0];
    while(non.size()){
        int i = non.back()+1;
        non.pop_back();
        while(i <= n && arr[i] == -1){
            bool f = false;
            for(int j = 1; j <= k; ++j){
                if(j != arr[i-1] && j != arr[i+1]){
                    f = true;
                    arr[i] = j;
                    break;
                }
            }
            if(!f){
                cout << "NO\n";
                return ;
            }
            i++;
        }
    }
    int i = lst-1;
    while(i > 0 && arr[i] == -1){
        bool f = false;
        for(int j = 1; j <= k; ++j){
            if(j != arr[i-1] && j != arr[i+1]){
                f = true;
                arr[i] = j;
                break;
            }
        }
        if(!f){
            cout << "NO\n";
            return;
        }
        i--;
    }
    cout << "YES\n";
    loop(i,1,n+1){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}
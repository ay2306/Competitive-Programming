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

bool check(V<V<int>> &a){
    int s3=0,s4=0;
    unordered_map<int,int> m;
    loop(i,0,3){
        int s1 = 0, s2=0;
        loop(j,0,3){
            m[a[i][j]]++;
            s1+=a[i][j];
            s2+=a[j][i];
        }
        s3+=a[i][i];
        s4+=a[i][2-i];
        if(s1 != 15 || s2 != 15)return false;
    }
    if(s3 != 15 || s4 != 15 || m.size() != 9)return false;
    return true;
}

V<V<V<int>>> all_magic_squares(){
    V<V<V<int>>> ans;
    V<V<int>> arr(3,V<int>(3));
    loop(i1,1,14){
        arr[0][0]=i1;
        int row1_left = 14-i1;
        loop(i2,1,row1_left+1){
            arr[0][1] = i2;
            arr[0][2] = 15-i1-i2;
            int col1_left = 14-i1;
            loop(i3,1,col1_left+1){
                arr[1][0]=i3;
                arr[2][0] = 15-arr[0][0]-arr[1][0];
                int col2_left = min(14-arr[1][0],14-arr[0][1]);
                loop(i4,1,col2_left+1){
                    arr[1][1] = i4;
                    arr[1][2] = 15-arr[1][0]-arr[1][1];
                    arr[2][1] = 15-arr[0][1]-arr[1][1];
                    arr[2][2] = 15-arr[2][0]-arr[2][1];
                    if(check(arr))ans.pb(arr);
                }
            }
        }
    }
    return ans;
}

int main(){
    auto ans = all_magic_squares();
    for(auto k: ans){
        for(auto i: k){
            for(auto j: i){
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
   return 0;
}
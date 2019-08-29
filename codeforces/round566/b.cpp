/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    int n,m;
    cin >> n >> m;
    V<string> a(n,"");
    loop(i,0,n){
        cin >> a[i];
    }
    int count = 0;
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j] == '*')count++;
        }
    }
    bool found = false;
    loop(i,0,n){
        loop(j,0,m){
            int up = 0;
            int down = 0;
            int right = 0;
            int left = 0;
            int k;
            k = i-1;
            if(a[i][j] != '*')continue;
            while(k >= 0 && a[k][j] == '*'){
                up++;
                k--;
            }
            k = i+1;
            while(k < n && a[k][j] == '*'){
                down++;
                k++;
            }
            k = j-1;
            while(k >= 0 && a[i][k] == '*'){
                left++;
                k--;
            }
            k = j+1;
            while(k < m && a[i][k] == '*'){
                right++;
                k++;
            }
            if(up + down + left + right + 1 == count && up > 0 && down > 0 && left > 0 && right > 0){
                found = true;
            }
        }
    }
    if(found){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}

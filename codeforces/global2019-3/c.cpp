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
#define pq priority_queue<ll,V<ll>,greater<ll>>
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    FAST
    int n;
    cin >> n;
    V<PII> ans;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    unordered_map<int,int> m;
    loop(i,0,n)m[arr[i]] = i;
    for(int i = 1; i < n; ++i){
        // cout << "Array = ";
        // loop(i,0,n)printf("(%d, %d) ",arr[i],m[arr[i]]);
        // cout << "\n";
        if(m[i] == i-1)continue;
        int current_index = m[i];
        if(abs(current_index-(i-1)) >= n/2){
            swap(arr[current_index],arr[i-1]);
            ans.pb(mp(i-1,current_index));
            m[arr[current_index]] = current_index;
            m[arr[i-1]] = i-1;
            // printf("CHANGE 1 for i = %d\n",i);
        }
        else if(i-1 < n/2){
            if(m[i] >= n/2){
                ans.pb(mp(current_index,0));
                ans.pb(mp(0,n-1));
                ans.pb(mp(i-1,n-1));
                ans.pb(mp(current_index,0));
                swap(arr[current_index],arr[0]);
                swap(arr[0],arr[n-1]);
                swap(arr[i-1],arr[n-1]);
                swap(arr[current_index],arr[0]);
                m[arr[0]] = 0;
                m[arr[n-1]] = n-1;
                m[arr[current_index]] = current_index;
                m[arr[i-1]] = i-1;
                // printf("CHANGE 2 for i = %d\n",i);
            }else{
                ans.pb(mp(current_index,n-1));
                ans.pb(mp(i-1,n-1));
                swap(arr[current_index],arr[n-1]);
                swap(arr[i-1],arr[n-1]);
                m[arr[0]] = 0;
                m[arr[n-1]] = n-1;
                m[arr[current_index]] = current_index;
                m[arr[i-1]] = i-1;
                // printf("CHANGE 3 for i = %d\n",i);
            }
        }
        else{
            if(m[i] >= n/2){
                ans.pb(mp(current_index,0));
                ans.pb(mp(i-1,0));
                ans.pb(mp(current_index,0));
                swap(arr[current_index],arr[0]);
                swap(arr[i-1],arr[0]);
                swap(arr[current_index],arr[0]);
                m[arr[0]] = 0;
                m[arr[n-1]] = n-1;
                m[arr[current_index]] = current_index;
                m[arr[i-1]] = i-1;
                // printf("CHANGE 4 for i = %d\n",i);
            }else{
                ans.pb(mp(current_index,n-1));
                ans.pb(mp(0,n-1));
                ans.pb(mp(i-1,0));
                ans.pb(mp(n-1,0));
                swap(arr[current_index],arr[n-1]);
                swap(arr[0],arr[n-1]);
                swap(arr[i-1],arr[0]);
                swap(arr[n-1],arr[0]);
                m[arr[0]] = 0;
                m[arr[n-1]] = n-1;
                m[arr[current_index]] = current_index;
                m[arr[i-1]] = i-1;
                // printf("CHANGE 5 for i = %d\n",i);
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto &i: ans){
        cout << i.F+1 << " " << i.S + 1 << "\n";
    }
    // cout << "Array = ";
    // loop(i,0,n)cout << arr[i] << " ";
    return 0;
}
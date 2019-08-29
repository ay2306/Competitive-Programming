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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;

int main(){
    ll m,k;
    cin >> m >> k;
    if(m == 0){
        if(k == 0){
            cout << "0 0";
            return 0;
        }else{
            cout << "-1";
            return 0;
        }
    }
    if(m == 1){
        if(k == 0){
            cout << "0 0 1 1";
            return 0;
        }else{
            cout << "-1";
            return 0;
        }
    }
    if(k >= (1 << m)){
        cout << "-1";
        return 0;
    }
    loop(i,0,(1<<m)){
        if(i == k)continue;
        cout << i << " ";
    }
    cout << k << " ";
    loopr(i,(1<<m)-1,0){
        if(i == k)continue;
        cout << i << " ";
    }
    cout << k;
    return 0;
}
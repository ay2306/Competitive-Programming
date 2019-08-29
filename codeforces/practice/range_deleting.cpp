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
const ll N = 1e6 + 10;
V<int> pos[N];
int prefMax[N];
int arr[N];
int main(){
    ll n,x;
    cin  >> n >> x;
    loop(i,0,n){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
        prefMax[i] = max(arr[i],((i > 0)?prefMax[i-1]:arr[i]));
    }
    int p = 1;
    int lst = n+5;
    //We are calculating p such that if we delete all numbers beneath p then array would be sorted
    //example array = 3 2 1 4 5 6 7 8, then p = 3
    //Thus if we delete x < p i.e. 1,2 then array will become sorted.
    for(int i = x; i >= 1; --i){
        if(pos[i].empty()){
            p = i;
            continue;
        }
        if(pos[i].back() > lst)break;
        p = i;
        lst = pos[i][0];
    }
    // printf("p  = %d\n",p);
    ll res = 0;
    lst = -1;
    //Consider array 3 2 1 4 5
    //when i = 1, r becomes 2
    //since lst == -1 r remains same
    //to make sorted array ending at 1

    for(int i = 1; i <= x; ++i){
        printf("For i = %d\n",i);
        int r = max(i,p-1);
        printf("r becomes max of (i = %d, p-1 = %d)\n",i,p-1);
        if(lst != -1 ){r = max(r,prefMax[lst]);printf("Since lst != -1, therefore r = max of (r = %d, prefMax[%d] = %d)\n",max(i,p-1),lst,prefMax[lst]);}
        printf("Making (x-r+1) = (%lld - %d + 1) = %lld added to res\n",x,r,(x-r+1));
        res += (x-r+1);
        if(!pos[i].empty()){
            printf("i is placed there for pos[i][0] = %d but lst was this %d, so beware\n",pos[i][0],lst);
            if(pos[i][0] < lst)break;
            lst = pos[i].back();
        }
    }
    cout << res;

    return 0;
}
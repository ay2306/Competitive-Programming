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

int main(){
    int n;
    cin >> n;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    V<PII> ans(n,{-1,-1});
    V<PII> ans2(n,{-1,-1});
    stack<int> s;
    PII over = {inf,inf};
    loop(i,0,n){
        while(s.size() && arr[s.top()] < arr[i]){
            PII c = {s.top(),i};
            if(ans[s.top()].F != -1 && ans[s.top()].S != -1){
                c = {ans[s.top()].F,i};
            }
            if(c.S-c.F > ans[i].S-ans[i].F || (c.S-c.F == ans[i].S-ans[i].F && c < ans[i])){
                ans[i] = c;
            }
            s.pop();
        }
        s.push(i);
    }
    while(s.size())s.pop();
    loopr(i,n-1,0){
        while(s.size() && arr[s.top()] < arr[i]){
            PII c = {i,s.top()};
            if(ans2[s.top()].F != -1 && ans2[s.top()].S != -1){
                c = {i,ans2[s.top()].S};
            }
            if(c.S-c.F > ans2[i].S-ans2[i].F || (c.S-c.F == ans2[i].S-ans2[i].F && c < ans2[i])){
                ans2[i] = c;
            }
            s.pop();
        }
        s.push(i);
    }
    while(s.size())s.pop();
    unordered_map<ll,int> prev;
    loop(i,0,n){
        if(prev.find(arr[i]) == prev.end()){
            prev[arr[i]] = i;
            continue;
        }
        if(i - prev[arr[i]] > over.S - over.F){
            over = {prev[arr[i]],i};
        }
        else if(i - prev[arr[i]] == over.S - over.F && prev[arr[i]] < over.F){
            over = {prev[arr[i]],i};
        }
        prev[arr[i]] = i;
    }
    loop(i,0,n){
        if(ans[i].S - ans[i].F > over.S-over.F){
            over = ans[i];
        }
        if(ans2[i].S - ans2[i].F > over.S-over.F){
            over = ans2[i];
        }
        else if(ans2[i].S - ans2[i].F == over.S-over.F && ans2[i].F < over.S){
            over = ans2[i];
        }
    }
    cout << over.F+1 << " " << over.S+1;
   return 0;
}
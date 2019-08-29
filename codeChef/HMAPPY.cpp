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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

// bool Compare(PLL a, PLL b){
//     return a.first >= b.first;
// }

// class Compare{
// public:
//     bool
// };

void solve(){
    ll n,m;
    cin >> n >> m;
    priority_queue<PLL, V<PLL> > pq;
    PLL *arr = new PLL[n];
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        arr[i].first = a;
    }
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        arr[i].second = a;
        arr[i].first*=arr[i].second;
        pq.push(arr[i]);
        // cout << "EH\n";
    }    
    if(n == 1){
        cout << max(1LL * 0,arr[0].first-m)*arr[0].second;
        return ;
    }
    while(m){
        if(pq.top().first == 0)break;
        PLL tmp = pq.top();
        pq.pop();
        ll diff = tmp.first - pq.top().first;
        diff/=tmp.second;
        if(tmp.second*(diff+1)<=tmp.first)diff++;
        m-=diff;
        tmp.first -= (tmp.second*diff);
        if(tmp.first > 0)pq.push(tmp);
    }
    if(pq.size())cout << pq.top().first;
    else cout << "0";
}

int main(){
    FAST
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
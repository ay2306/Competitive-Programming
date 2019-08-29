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
#define FILE_READ freopen("input.txt","r",stdin);
#define FILE_OUT freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    // FILE_READ
    priority_queue<ull, V<ull> > p;
    int n;
    ull ans = 0;
    cin >> n;
    V<ull> v;
    for(int i = 0; i < n; ++i){
        ull a;
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(),v.end(),greater<ull>());
    p.push(v[0]);
    for(int i = 1; i < n; ++i){
        if(i+1 == n){
            if(p.size() && p.top() > v[i]){
                ans++;
            }
        }else{
            if(p.top() > v[i]){
                p.pop();
                ans++;
            }
            p.push(v[i]);
        }
    }
    cout << ans;
    return 0;
}
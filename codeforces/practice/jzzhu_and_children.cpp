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

using namespace std;


int main(){
    int n,m;
    V<P<int,int> > q;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        q.push_back(mp(a,i));
    }
    P<int,int> a;
    while(!q.empty()){
        a = q[0];
        a.first-=m;
        if(a.first > 0)q.pb(a);
        q.erase(q.begin());
    }
    cout << a.second;
    return 0;
}
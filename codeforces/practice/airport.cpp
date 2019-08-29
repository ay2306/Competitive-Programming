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
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int> > minpq;
    priority_queue<int, vector<int> > maxpq;
    for(int i=0,a; i < m; ++i){
        cin >> a;
        minpq.push(a);
        maxpq.push(a);
    }
    int mn=0,mx=0;
    for(int i = 0; i < n; ++i){
        mx+=maxpq.top();
        mn+=minpq.top();
        int a = maxpq.top();
        int b = minpq.top();
        maxpq.pop();
        minpq.pop();
        if(b-1 > 0)minpq.push(b-1);
        if(a-1 > 0)maxpq.push(a-1);
    }
    cout << mx << " " << mn;
    return 0;
}
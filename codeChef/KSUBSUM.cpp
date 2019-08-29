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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

void solve(){
    int n,k1,k2,k3;
    cin >> n >> k1 >> k2 >> k3;
    V<int> arr(n+1,0);
    loop(i,1,n+1){
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }
    priority_queue<int,V<int>, greater<int> > p;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
                int x=arr[i]-arr[j-1];
				if(p.size()<k3) p.push(x);
				else
				{
					if(x>p.top())
					{
						p.pop();p.push(x);
					}
				}
        }
    }
    V<int> c(k3+1);
    int k = k3;
    while(p.size()){
        c[k--] = p.top();
        p.pop();
    }
    // reverse(c.begin(),c.end());
    cout << c[k1] << " " << c[k2] << " " << c[k3] << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
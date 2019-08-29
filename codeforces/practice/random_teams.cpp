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
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

// if((max(dataset[unit[i]])-min(dataset[unit[i]]))<10000000):

int main(){
    ll a,b;
    cin >> a >> b;
    ll mx = ((a-b)*(a-b+1))/2;
    mx = max((ll)0,mx);
    ll t = a/b;
    ll l = a%b;
    // Number of equal distribution = a/b
    // Number of teams getting more extra members = a%b;
    // Members of a%b teams = a/b + 1
    // Member of n - a%b teams = a/b;
    ll v = (a%b)*(t*(t+1)/2);
    ll mn = max((ll)0,v);
    v = (b - a%b)*(t*(t-1)/2);
    v = max((ll)0,v);
    mn+=v;
    cout << mn << " " << mx;
    return 0;
}
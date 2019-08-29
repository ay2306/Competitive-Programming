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
    ll x,y;
    PLL p[2];
    cin >> x >> y;
    int f=1,s=1;
    if(x<0){
        x*=-1;
        f=-1;
    }
    if(y<0){
        y*=-1;
        s = -1;
    }
    p[0].first = f*(x+y);
    p[0].second = 0;
    p[1].second = s*(x+y);
    p[1].first = 0;
    sort(p,p+2);
    cout << p[0].first << " " << p[0].second << " " << p[1].first << " " << p[1].second;   
    return 0;
}
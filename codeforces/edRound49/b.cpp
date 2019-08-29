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
int main(){
    ll n,o;
    int q;
    cin >> n >> q;
    ll half = n/2;
    o = n*n;
    o/=2;
    if(n%2 == 1){half++;o++;}
    // cout << o;
    while(q--){
        ll x,y;
        cin >> x >> y;
        if((x+y)%2 == 0){
            ll k = ((x-1)/2)*n;
            if((x-1)%2 == 1)k+=(half);
            cout << k+((y+1)/2);
        }else{
            // swap(x,y);
            // x--; y--;
            ll k = ((x-1)/2)*n;
            // cout << k << endl;
            if((x-1)%2 == 1 )k+=(n/2);
            // cout << k << endl;
            cout << (k + ((y+1)/2)) + (o);
        }
        cout << "\n";
    }
    return 0;
}
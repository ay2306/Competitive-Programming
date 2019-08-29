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
    ll n,a,b;
    cin >> n >> a >> b;
    // cout << n << a << b << endl;
    if(a*b >= 6*n){
        cout << a*b << endl << a << " " << b;
        return 0;
    }
    bool f = 0;
    if(a > b){swap(a,b);f=1;}
    ll SQ = 1e18, a1,b1,tmp;
    for(ll i = a; (i*i) <= (6*n); ++i){
        // cout << "EJJE\n";
        tmp = 6*n/i;
        if(tmp*i < 6*n)tmp++;
        if(tmp < b)continue;
        if(tmp * i < SQ ){
            SQ = tmp*i;
            a1 = i;
            b1 = tmp;
        }
    }
    if(f)swap(a1,b1);
    cout << a1*b1 << endl << a1 << " " << b1; 
    return 0;
}
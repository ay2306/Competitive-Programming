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


ll power(ll a, ll n){
    if(n == 1)return a;
    ll p = power(a,n/2);
    p = (p%MOD * p%MOD)%MOD;
    if(n%2)p = (p%MOD * a%MOD)%MOD;
    return p;
}


class tree{
public:
    ll left;
    ll right;
    ll top;
    ll bottom;
    ll edges;
    tree(ll n){
        left = n;
        right = n;
        top = 1;
        bottom = power(2,n-1);
        edges = (power(2,n)-2+MOD)%MOD;
    }
    void rLeft(){
        bottom*=2;
        top*=2;
        ll k = edges*2;
        edges = k + left;
        ss();
    }
    void rRight(){
        bottom*=2;
        top*=2;
        ll k = edges*2;
        edges = k + left;
        ss();
    }
    void rBottom(){
        left*=2;
        right*=2;
        ll k = edges*2;
        edges = k + bottom;
        bottom = top;
        ss();
    }
    void rTop(){
        left*=2;
        right*=2;
        ll k = edges*2;
        edges = k + top;
        top = bottom;
        ss();
    }
    void ss(){
        left%=MOD;
        right%=MOD;
        top%=MOD;
        bottom%=MOD;
        edges%=MOD;
    }
    void show(){
        printf("top = %lld, right = %lld, bottom = %lld, left = %lld, edges = %lld\n",top,right,bottom,left,edges);

    }
    
};

int main(){
    ll n,q;
    cin >> n >> q;
    tree t(n+1);
    // t.show();
    while(q--){
        ll a,b;
        cin >> a;
        if(a == 1){
            cin >> b;
            switch(b){
                case 1: t.rRight(); break;
                case 2: t.rLeft(); break;
                case 3: t.rTop(); break;
                case 4: t.rBottom(); break;
            }
            // t.show();
        }else{
            cout << t.edges << "\n";
        }
    }
    return 0;
}
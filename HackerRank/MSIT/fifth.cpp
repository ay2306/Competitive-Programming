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
using namespace std;

const ll maxn = 1e5;

struct matrix{
    P<ll,PLL> row1;
    P<ll,PLL> row2;
    P<ll,PLL> row3;
};

matrix multiply(matrix a, matrix b){
    matrix c;
    c.row1.F = (a.row1.F*b.row1.F + a.row1.S.F*b.row2.F + a.row1.S.S*b.row3.F)%MOD;
    c.row1.S.F = (a.row1.F*b.row1.S.F + a.row1.S.F*b.row2.S.F + a.row1.S.S*b.row3.S.F)%MOD;
    c.row1.S.S = (a.row1.F*b.row1.S.S + a.row1.S.F*b.row2.S.S + a.row1.S.S*b.row3.S.S)%MOD;

    c.row2.F = (a.row2.F*b.row1.F + a.row2.S.F*b.row2.F + a.row2.S.S*b.row3.F)%MOD;
    c.row2.S.F = (a.row2.F*b.row1.S.F + a.row2.S.F*b.row2.S.F + a.row2.S.S*b.row3.S.F)%MOD;
    c.row2.S.S = (a.row2.F*b.row1.S.S + a.row2.S.F*b.row2.S.S + a.row2.S.S*b.row3.S.S)%MOD;
    
    c.row3.F = (a.row3.F*b.row1.F + a.row3.S.F*b.row2.F + a.row3.S.S*b.row3.F)%MOD;
    c.row3.S.F = (a.row3.F*b.row1.S.F + a.row3.S.F*b.row2.S.F + a.row3.S.S*b.row3.S.F)%MOD;
    c.row3.S.S = (a.row3.F*b.row1.S.S + a.row3.S.F*b.row2.S.S + a.row3.S.S*b.row3.S.S)%MOD;

    return c;
}

matrix power(matrix c, ll n){
    if(n == 1)return c;
    matrix d = power(c,n/2);
    d = multiply(d,d);
    if(n%2)d = multiply(d,c);
    return d;
}


int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << "1";
    }else if(n == 2){
        cout << "2";
    }else if(n == 3){
        cout << "4";
    }else{
        matrix res;
        res.row1 = mp(1,mp(1,1));
        res.row2 = mp(1,mp(0,0));
        res.row3 = mp(0,mp(1,0));
        res = power(res,n-3);
        // cout << res.row1.F << " " << res.row1.S.F << " " << res.row1.S.S << "\n";
        // cout << res.row2.F << " " << res.row2.S.F << " " << res.row2.S.S << "\n";
        // cout << res.row3.F << " " << res.row3.S.F << " " << res.row3.S.S << "\n";
        ll ans = res.row1.F + res.row1.S.F*2 + res.row1.S.S*4;
        ans = ans;
        cout << ans;
    }
    return 0;
}
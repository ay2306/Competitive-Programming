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
V<ll> arr;

V<V<double> > findInverse(V<V<ll> > mat){
    int n = mat.size();
	
    int i, j;
	V<V<double> > result;
    double determinant = 0;
	
	
	for(i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			result[i][j] = ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
		
	}
    return result;
}


ll power(ll a, ll n){
    if(n == 0)return 1;
    ll p = power(a,n/2);
    p*=p;
    if(n%2)p*=a;
    return p;   
}

void solve(){
    int s,c;
    cin >> s >> c;
    arr = V<ll> (s);
    loop(i,0,s)cin >> arr[i];
    V<V<ll> > mat;
    for(int row = 0; row < 10; ++row){
        V<ll> t;
        for(int col = 1; col <= 10; ++col){
            t.push_back(pow(col,row));
        }
        mat.pb(t);
    } 
    auto inv = findInverse(mat);
    V<double> p(10,0.0);
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j)p[i]+=inv[j][i];
    }
    for(int i = 0; i < 10; ++i)p[i]*=arr[i];
    V<ll> res;
    for(int i = 1; i <= c; ++i){
        double k = 0;
        for(int j = 0; j < 10; ++j)k+=(power(s+c,k)*p[j]);
        k = round(k);
        res.pb(long(k));
    }
    for(auto i: res)cout << i << " ";
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}	
/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n%2){
        p*=a;
        p%=MOD;
    }
    return p;
}

vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b){
    vector<vector<ll>> ans (3,vector<ll> (3,0));
    loop(i,0,3){
        loop(j,0,3){
            loop(k,0,3){
                ll pr = a[i][k]*a[k][j];
                pr%=(MOD-1);
                ans[i][j]+=pr;
                ans[i][j]%=(MOD-1);
            }
        }
    }
    return ans;
}

vector<vector<ll>> power(vector<vector<ll>> a,ll n){
    if(n == 0){
        return vector<vector<ll>> (3,vector<ll>(3,1));
    }
    if(n == 1){
        return a;
    }
    auto p = power(a,n/2);
    p = multiply(p,p);
    if(n%2){
        p = multiply(p,a);
    }
    return p;
}


int main(){
    ll n,f1,f2,f3,c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    n-=3;
    if(n == 1){
        c = power(c,2);
        f1 = power(f1,1);
        f2 = power(f2,1);
        f3 = power(f3,1);
        ll ans = c;
        ans%=MOD;
        ans*=f1;
        ans*=f2;
        ans%=MOD;
        ans*=f3;
        ans%=MOD;
        cout << ans << "\n";
        return 0;
    }
    if(n == 2){
        c = power(c,6);
        f1 = power(f1,1);
        f2 = power(f2,2);
        f3 = power(f3,2);
        ll ans = c;
        ans*=f1;
        ans%=MOD;
        ans*=f2;
        ans%=MOD;
        ans*=f3;
        ans%=MOD;
        cout << ans << "\n";
        return 0;
    }
    if(n == 3){
        c = power(c,14);
        f1 = power(f1,2);
        f2 = power(f2,3);
        f3 = power(f3,4);
        ll ans = c;
        ans*=f1;
        ans%=MOD;
        ans*=f2;
        ans%=MOD;
        ans*=f3;
        ans%=MOD;
        cout << ans << "\n";
        return 0;
    }
    V<V<ll>> mat(3,V<ll> (3));
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[0][2] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 1;
    mat[2][2] = 0;
    auto p = power(mat,n-3);
    ll cal3 = p[0][2] + 2*p[0][1] + 4*p[0][0];
    cal3%=(MOD-1);
    ll cal2 = p[0][2] + 2*p[0][1] + 3*p[0][0];
    cal2%=(MOD-1);
    ll cal1 = p[0][2] + 1*p[0][1] + 2*p[0][0];
    cal1%=(MOD-1);
    ll c1 = n;
    c1%=(MOD-1);
    ll c2 = n-1;
    c2%=(MOD-1);
    c = power(c,(c1*c2)%(MOD-1));
    f1 = power(f1,cal1);
    f2 = power(f2,cal2);
    f3 = power(f3,cal3);
    ll ans = c;
    ans*=f1;
    ans%=MOD;
    ans*=f2;
    ans%=MOD;
    ans*=f3;
    ans%=MOD;
    cout << ans << "\n";
    return 0;
}
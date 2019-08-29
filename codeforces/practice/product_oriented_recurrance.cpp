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
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
template<class T>
class matrix{
    size_t ROW,COL;
public:
    vector<vector<T>> mat;
    matrix(size_t N, size_t M, int populate = 0){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    matrix(size_t N){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,0));
    }
    void __init(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cin  >> this->mat[i][j];
                mat[i][j]%=(MOD-1);
            }
        }
    }
    void __init(vector<vector<T>> arr){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                this->mat[i][j] = arr[i][j];
                mat[i][j]%=(MOD-1);
            }
        }
    }
    void __display(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    matrix<T> operator*(const matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES";
        }
        matrix<T> result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result.mat[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result.mat[_i][_j]+=(((this->mat[_i][_k]%(MOD-1))*(rhs.mat[_k][_j]%(MOD-1)))%(MOD-1));
                    result.mat[_i][_j]%=(MOD-1);
                }
            }
        }
        return result;
    }
    matrix<T> power(int n){
        if(n == 0)return matrix<T>(this->ROW, this->COL,1);
        if(n == 1)return *this;
        matrix p = power(n/2);
        p = p*p;
        if(n%2)p = p*(*this);
        return p;
    }
};


ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n%2)p*=a;
    p%=MOD;
    return p;
}

int main(){
    ll n,f[4],c,power1,power2,power3,totalC;
    cin >> n;
    loop(i,1,4)cin >> f[i];
    cin >> c;
    matrix<ll> a(3);
    a.__init(V<V<ll>> ({{1,1,1,},{1,0,0},{0,1,0}}));
    a = a.power(n-3);
    power3 = (a.mat[0][0])%(MOD-1);
    power2 = (a.mat[0][1])%(MOD-1);
    power1 = (a.mat[0][2])%(MOD-1);
    totalC = ((power3*3)%(MOD-1) + (power2*2)%(MOD-1) + power1%(MOD-1))%(MOD-1);
    ll ans = 1;
    ans*=power(f[1],power1);
    ans%=MOD;
    ans*=power(f[2],power2);
    ans%=MOD;
    ans*=power(f[3],power3);
    ans%=MOD;
    ans*=power(c,totalC);
    ans%=MOD;
    n%=(MOD-1);
    n*=(MOD-2);
    n%=(MOD-1);
    ans*=power(c,n);
    ans%=MOD;
    cout << ans;
   return 0;
}

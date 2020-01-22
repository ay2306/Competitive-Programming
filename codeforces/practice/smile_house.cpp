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
    vector<vector<T>> mat;
public:
    matrix(){}
    matrix(size_t N, size_t M, int populate = 0){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    matrix(size_t N, int populate = 0){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    void __init(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cin  >> this->mat[i][j];
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
    vector<T> &operator[] (int index){
        return this->mat[index];
    }
    matrix<T> operator*(const matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES";
        }
        matrix<T> result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result[_i][_j] = INT_MIN;
                for(int _k = 0; _k < this->COL; ++_k){
                    result[_i][_j]=max(result[_i][_j],this->mat[_i][_k]+rhs.mat[_k][_j]);
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

int main(){
    int n,k;
    cin >> n >> k;
    matrix<ll> res(n,n,INT_MIN);
    matrix<ll> pw[10];
    pw[0]=res;
    loop(i,0,n){
        pw[0][i][i] = 0;
    }
    while(k--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        pw[0][a][b] = c;
        pw[0][b][a] = d;
    }
    loop(i,1,10){
        pw[i] = pw[i-1]*pw[i-1];
    }
    loop(i,0,n){
        res[i][i] = 0;
    }
    ll ans = 0;
    // loop(o,0,n){
    //     loop(o1,0,n)cout << [o][o1] << " ";
    //     cout << endl;
    // }
    loopr(i,9,0){
        bool ok = 1;
        auto m = pw[i]*res;
        loop(j,0,n){
            if(m[j][j] > 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            res = m;
            ans+=(1LL << i);
        }
    }
    if(++ans > n)ans = 0;
    cout << ans;
   return 0;
}
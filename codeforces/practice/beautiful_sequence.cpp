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

int main(){
    int a,b,c,d;
    int a1,b1,c1,d1;
    cin >> a >> b >> c >> d;
    if(a > b+1 || d > c+1){
        cout << "NO\n";
        return 0;
    }
    if(a == b+1 && c == 0 && d==0){
        cout << "YES\n";
        cout << 0;
        loop(i,0,b)cout << " 1 0";
        cout << "\n";
        return 0;
    }
    if(a == 0 && b == 0 && d == c+1){
        cout << "YES\n";
        cout << 3;
        loop(i,0,c)cout << " 2 3";
        cout << "\n";
        return 0;
    }
    b-=a;
    c-=d;
    if(b >= 0 && c >=0 && abs(c-b)<2){
        cout << "YES\n";
        if(b > c){
            cout << "1 ";loop(i,0,a)cout << "0 1 ";loop(i,0,c)cout << "2 1 "; loop(i,0,d)cout << "2 3 ";
            cout << endl;
        }else{
            loop(i,0,a)cout << "0 1 ";loop(i,0,b)cout << "2 1 "; loop(i,0,d)cout << "2 3 ";
            if(b < c)cout << "2 ";
            cout << endl;
        }
    }else{
        cout << "NO\n";
    }
   return 0;
}
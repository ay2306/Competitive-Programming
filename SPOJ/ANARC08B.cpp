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
string a;
unordered_map<int,int> m;
unordered_map<int,int> m1;
int getNumber(string k){
    int num = 0;
    for(int i = 0; i+2 < k.size(); i+=3){
        int o = (k[i]-'0')*100 + (k[i+1]-'0')*10 + (k[i+2]-'0');
        o = m[o];
        num*=10;
        num+=o;
    }
    return num;
}
string getString(int num){
    string ans = "";
    string a = to_string(num);
    for(auto &i: a){
        int val = m1[i-'0'];
        string k = to_string(val);
        while(k.size() < 3){
            k = "0"+k;
        }
        ans+=k;
    }
    return ans;
}
int main(){
    FAST
    m[(1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6)] = 8;
    m[(1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5)] = 0;
    m[(1 << 1) + (1 << 3)] = 1;
    m[(1 << 0) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6)] = 2;
    m[(1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 6)] = 3;
    m[(1 << 1) + (1 << 3) + (1 << 5) + (1 << 6)] = 4;
    m[(1 << 0) + (1 << 1) + (1 << 2) + (1 << 5) + (1 << 6)] = 5;
    m[(1 << 0) + (1 << 1) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6)] = 6;
    m[(1 << 0) + (1 << 1) + (1 << 3)] = 7;
    m[(1 << 0) + (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6)] = 9;

    m1[8] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6);
    m1[0] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5);
    m1[1] = (1 << 1) + (1 << 3);
    m1[2] = (1 << 0) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6);
    m1[3] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 6);
    m1[4] = (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6);
    m1[5] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 5) + (1 << 6);
    m1[6] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6);
    m1[7] = (1 << 0) + (1 << 1) + (1 << 3);
    m1[9] = (1 << 0) + (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6);
    while(1){
        cin >> a;
        if(a == "BYE")break;
        string a1="",a2="",ans="";
        int i = 0;
        while(a[i] != '+')a1+=a[i++];
        i++;
        while(a[i] != '=')a2+=a[i++];
        int n1 = getNumber(a1);
        int n2 = getNumber(a2);
        ans = getString(n1+n2);
        // printf("n1 = %d n2= %d and sum = %d\n",n1,n2,n1+n2);
        cout << a << ans << "\n";
    }
   return 0;
}
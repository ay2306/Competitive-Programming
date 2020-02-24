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

int main(){
    map<int,V<int>> m;
    int arr[4] = {1,6,8,9};
    do{
        int k = 0;
        loop(i,0,4)k=(k*10+arr[i]);
        if(m.find(k%7) == m.end()){
            V<int> a;
            loop(i,0,4)a.emplace_back(arr[i]);
            m[k%7]=a;
        }
        if(m.size() == 7)break;
    }while(next_permutation(arr,arr+4));
    string a;
    cin >> a;
    int c = 0;
    map<char,int> m1;
    for(auto &i: a)m1[i]++;
    c=m1['0'];
    m1.erase(m1.find('0'));
    m1['1']--;
    m1['6']--;
    m1['8']--;
    m1['9']--;
    string ans = "";
    V<int> p(a.size(),1);
    loop(i,1,a.size()){
        p[i]=p[i-1]*3;
        p[i]%=7;
    }
    int md = 0;
    int j = 0;
    reverse(all(p));
    for(auto &i: m1){
        loop(k,0,i.S){
            ans+=i.F;
            md+=((p[j++]*(i.F-'0'))%7);
            md%=7;
        }
    }
    // cout << md << "\n";
    md = (7-md)%7;
    if(ans.size() == 0){
        for(auto &i: m[md])ans+=char(i+'0');
        while(c--)ans+="0";
    }else{
        while(c--)ans+="0";
        for(auto &i: m[md])ans+=char(i+'0');
    }
    cout << ans;
   return 0;
}
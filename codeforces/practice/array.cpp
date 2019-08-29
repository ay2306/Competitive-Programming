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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    V<int> v1,v2,v3;
    int n,a;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a > 0)v2.pb(a);
        if(a < 0)v1.pb(a);
        if(a == 0)v3.pb(a);
    }   
    if(v2.size() == 0){
        v2.pb(v1[0]);
        v2.pb(v1[1]);
        v1.erase(v1.begin());
        v1.erase(v1.begin());
    }
    if(v1.size() %2 ==0){
        v3.pb(v1[0]);
        v1.erase(v1.begin());
    }
    cout << v1.size() << " ";
    for(int i = 0; i < v1.size(); ++i)cout << v1[i] << " ";
    cout << endl;
    cout << v2.size() << " ";
    for(int i = 0; i < v2.size(); ++i)cout << v2[i] << " ";
    cout << endl;
    cout << v3.size() << " ";
    for(int i = 0; i < v3.size(); ++i)cout << v3[i] << " ";
    return 0;
}
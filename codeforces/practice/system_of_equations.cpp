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
    int n,m;
    cin >> n >> m;
    V<int> a;
    V<int> b;
    for(int i = 0; i <= n; ++i){
        if(int(sqrt(n-i))*int(sqrt(n-i)) == n-i){
            b.pb(i);
        }
    }
    for(int i = 0; i <= m; ++i){
        if(int(sqrt(m-i))*int(sqrt(m-i)) == m-i){
            a.pb(i);
        }
    }
    int c = 0;
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < b.size(); ++j){
            if((a[i]*a[i] + b[j] == n)&&(a[i] + b[j]*b[j] == m))c++;
        }
    }
    cout << c;
    return 0;
}
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
int main(){
    int a,n,t;
    cin >> n;
    t = n;
    V<int> v(n,1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a;
            if(a == 1 || a == 3){if(v[i])t--;v[i] = 0;}
            if(a == 2 || a == 3){if(v[j])t--;v[j] = 0;}
        }
    }
    cout << t << endl;
    for(int i = 0; i < v.size(); ++i){
        if(v[i]) cout << i+1 << " ";
    }

    return 0;
}
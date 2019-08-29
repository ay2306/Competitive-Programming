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
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    int k,n,m;
    char f,l;
    cin >> n >> m;
    if(n >= m){f='B';l='G';k=m;}
    else{f='G';l='B';k=n;}
    for(int i = 0; i < k; ++i){
        cout << f << l;
    }
    for(int i = k; i < n || i < m; ++i){
        cout << f;
    }
    
    return 0;
}
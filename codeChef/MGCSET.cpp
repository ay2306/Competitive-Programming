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

void solve(){

    unsigned long long int a = 1;
    M<int,int> m;
    int b,n,k,c=0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> b;
        if(b%k == 0){
            c++;
            if(m.count(b) == 0){
                m.insert(mp(b,1));
            }else{
                m.find(b)->second++;
            }
        }
    }
    a = (1 << c)-1;
    for(M<int,int>::IT i = m.begin(); i != m.end(); ++i){
        c/=i->second;
    }
    cout << a << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
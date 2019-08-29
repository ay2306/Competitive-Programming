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

ull ans(ull n, ull k){
    if(n == 0)return 1;
    if(n == 1)return k%MOD;
    if(n%2 == 0){
        return ((ans(n/2,((k%MOD)*(k%MOD)%MOD))%MOD))%MOD;
    }else{
        return ((k%MOD)*(ans(n-1,k)%MOD))%MOD;
    }
}

void solve(){
    ull n,k;
    cin >> n >> k;
    ull a = k%MOD;
    if(k == 1){
        cout << "1\n";
        return ;
    }
    if(n == 1){
        cout << k%MOD << endl;
        return ;
    }
    if(n%2 == 0){
        for(ull i = 1; i <=n/2; i*=2){
            a = ((a%MOD)*((ans(i,k)+1)%MOD))%MOD;
        }
    }else{
        for(ull i = 1; i <=(n-1)/2; i*=2){
            a = ((a%MOD)*((ans(i,k)+1)%MOD))%MOD;
        }
        a = ((a%MOD)+(ans(n,k)%MOD))%MOD;
    }
    cout << a << endl;
}

int main(){
    ull t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int main(){
    ll a;
    int sp = 0;
    ll b;
    cin >> a >> b;
    if(a < b){swap(a,b);sp=1;}
    ll k1 = -1 + sqrt(1 + 8*a); 
    k1/=2;
    ll k2 = -1 + sqrt(1 + 8*(a+b)); 
    k2/=2;
    // cout <//<
    // k1 = (k1*(k1+1))/2;
    ll startk1= 1;
    // cout << a << " " << b << "\n";
    
    while(((k1+2)*(k1+2))/2 - ((startk1+2)*(startk1+1))/2 <= a){
        // cout << ((k1+2)*(k1+2))/2 - ((startk1+2)*(startk1+1))/2 << "\n";
        startk1++;
        k1++;
    }
    // cout << "ANS\n";
    // cout << k1 << " " <<  startk1 << "\n";
    vector<ll> a1;
    vector<ll> a2;
    for(ll i = startk1; i <= k1; ++i){
        a1.pb(i);
    }
    ll sum = 0;
    for(ll i = 1; i < startk1; ++i){
        if(sum+i > b)break;
        a2.pb(i);
        sum+=i;
    }
    for(ll i = k1+1; ; ++i){
        if(sum+i > b)break;
        a2.pb(i);
        sum+=i;
    }
    if(sp){
        cout << a2.size() << "\n";
        for(auto i: a2)cout << i << " ";
        cout << "\n";
        cout << a1.size() << "\n";
        for(auto i: a1)cout << i << " ";
    }else{
        cout << a1.size() << "\n";
        for(auto i: a1)cout << i << " ";
        cout << "\n";
        cout << a2.size() << "\n";
        for(auto i: a2)cout << i << " ";
    }
    return 0;
}
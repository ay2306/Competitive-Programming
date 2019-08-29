/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int main(){
    ll n,k;
    cin >> n >> k;
    int bit = 0;
    int bits = 0;
    ll j = n;
    while(j){
        bit+=(j%2);
        bits++;
        j/=2;
    }
    if(k < bit || k > n){
        cout << "NO\n";
        return 0;
    }
    priority_queue<ll,V<ll> > p;
    j = 1;
    for(int i = 0; (n >> i) > 0; ++i){
        if(((n>>i)&1) == 1){
            p.push((j<<i));
        }
    }
    while(p.size()!= k){
        ll k = p.top();
        p.pop();
        p.push(k/2);
        p.push(k/2);
    }
    cout << "YES\n";
    while(p.size()){
        cout << p.top() << " ";
        p.pop();
    }
    return 0;
}
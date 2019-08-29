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
using namespace std;

const ll maxn = 1e5;
bool comp(P<PII,int> a, P<PII,int> b){
    if(a.F.F > b.F.F)return true;
    if(a.F.F < b.F.F)return false;
    if(a.F.S < b.F.S)return true;
    if(a.F.S > b.F.S)return false;
}
int main(){
    int n;
    cin >> n;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    pair<PII,int> kk = mp(mp(100,-1),0);
    V<P<PII,int> > a(n);
    loop(i,0,n){
        ll k = arr[i];
        P<PII,int> tt = mp(mp(0,0),i);
        while(k && k%3 == 0){
            tt.F.F++;
            k/=3;
        }
        while(k && k%2 == 0){
            tt.F.S++;
            k/=2;
        }
        a[i] = tt;
    }
    sort(a.begin(),a.end(),comp);
    for(auto i: a){
        cout << arr[i.S] << " ";
    }

    return 0;
}
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
int main(){
    ll n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    for(ll i = 0; i < k; ++i){
        ll ti,fi,tf,ff;
        cin >> ti >> fi >> tf >> ff;
        if(tf == ti){
            cout << abs(fi-ff) << endl;
        }
        else if(fi < a){
            ll c1 = abs(fi-a);
            c1 += abs(ti-tf);
            c1 += abs(ff-a);
            cout << c1 << endl;
        }else if(fi > b){
            ll c1 = abs(fi-b);
            c1 += abs(ti-tf);
            c1 += abs(ff-b);
            cout << c1 << endl;
        }else{
            ll c1 = abs(fi-ff);
            c1 += abs(tf-ti);
            cout << c1 << endl;
        }
    }
    return 0;
}
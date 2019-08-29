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



class ProductThreshold{
public:
    ll subarrayCount(int N, int limit, V<int> Apprefix, int spread, int offset){
        V<ll> A;
        for(int i = 0; i < Apprefix.size(); ++i){
            A.pb(Apprefix[i]);
        }
        ll seed = ab(*Apprefix.rbegin());
        for(int i = Apprefix.size(); i < N; ++i){
            seed =  (seed * 1103515245 + 12345) % (1 << 31);
            A.pb((seed % spread) + offset);
        }
        ll ans = 0;
        ll p = 1;
        int j = 1;
        for(int i = 0; i < N; ++i){
            p*=A[i];
            for(; j < N; ++j){
                if(limit/p >= A[j]){
                    p*=A[j];
                }else{
                    j--;
                    break;
                }
            }
            p/=A[i];
            ans+=max(0,j-i);
        }
        return ans;
    }

    ll ab(ll a){
        if(a < 0)return -1*a;
        return a;
    }

};

int main(){
    ProductThreshold a;
    int N = 5;
    int limit = 5;
    V<int> v;
    int arr[] = {1,2,3,-4,5};
    ll spread = 1;
    ll offset = 1;
    for(int i = 0; i < N; ++i)v.pb(arr[i]);
    cout << a.subarrayCount(N,limit,v,spread,offset);  
    return 0;
}
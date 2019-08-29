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
#define tr(container, it) for(typeof(container.rbegin()) it = container.rbegin(); it != container.rend(); it++)
using namespace std;

int main(){
    int k,n;
    cin >> n;
    S<int> a,b;
    int a_m = 0;
    int b_m = 0;
    for(int i = 0; i < n; ++i){
        cin >> k;
        tr(a,itr){
            if(*itr <= a_m)break;
            if(__gcd(*itr,k) > a_m){
                a_m = __gcd(*itr,k);
            }
        }
        a.insert(k);
    }
    for(int i = 0; i < n; ++i){
        cin >> k;
        tr(b,itr){
            if(*itr <= b_m)break;
            if(__gcd(*itr,k) > b_m){
                b_m = __gcd(*itr,k);
            }
        }
        b.insert(k);
    }
    cout << a_m+b_m;
    return 0;
}
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
    int k;
    cin >> k;
    V<int> a;
    int sum = 0;
    for(int i = 0,b; i < 12; ++i){
        cin >> b;
        a.pb(b);
        sum+=b;
    }
    if(sum >= k){
        sort(a.begin(),a.end(),greater<int>() );
        sum = 0;
        int p = 0;
        for(int i = 0; i < 12; ++i){
            if(sum>=k)break;
            sum+=a[i];
            p++;
        }
        cout << p;
    }
    else  cout << "-1";

    return 0;
}
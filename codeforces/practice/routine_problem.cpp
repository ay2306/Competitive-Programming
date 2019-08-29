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
    double a1,a2,b1,b2,ur;
    long num,denom;
    cin >> a1 >> a2 >> b1 >> b2;
    if(((b2/b1)*a1) <= a2){
        denom = b1*a2;
        num = denom - b2*a1;
    }
    if(((b1/b2)*a2) <= a1){
    
        denom = b2*a1;
        num = denom - b1*a2;
        // ur = 1-((b2*a1)/(b1*a2));
        // ur = 1-((b1*a2)/(b2*a1));
    
    }
    ll g = __gcd(num,denom);
    cout << num/g << "/" << denom/g; 
    return 0;
}
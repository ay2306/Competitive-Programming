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
    FAST
    ll a,b,c,ans=0;
    ll a1,b1,c1,ans1=0;
    cin >> a >> b >> c;
    a1=((a%3 == 0 && a!=0)?3:(a%3));
    b1=((b%3 == 0 && b!=0)?3:(b%3));
    c1=((c%3 == 0 && c!=0)?3:(c%3));
    ans1 = min(a1,min(b1,c1));
    a1 = a-ans1;
    b1 = b-ans1;
    c1 = c-ans1;
    ans1+=(a1/3);
    ans1+=(b1/3);
    ans1+=(c1/3);
    ans+=(a/3);
    ans+=(b/3);
    ans+=(c/3);
    a%=3;
    b%=3;
    c%=3;
    
    // cout << a << " " << b << " " << c << " " << ans << "\n";
    ans+=min(a,min(b,c));
    cout << max(ans,ans1);
    return 0;
}
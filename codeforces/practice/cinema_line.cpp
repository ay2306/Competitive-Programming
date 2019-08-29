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
    // freopen("input.txt","r",stdin);    
    // freopen("output.txt","w+",stdout);
    ll fifty = 0, twenty_five=0;
    ll n;
    cin >> n;
    ll *a = new ll[n];
    for(int i = 0; i < n; ++i)cin >> a[i];
    for(int i = 0; i < n; ++i){
        if(a[i] == 25)twenty_five++;
        if(a[i] == 50){
            if(twenty_five > 0)twenty_five--;
            else{
                cout << "NO";
                return 0;
            }
            fifty++;
        }
        if(a[i] == 100){
            if(fifty > 0 && twenty_five > 0){
                twenty_five--;
                fifty--;
            }else if(twenty_five >= 3){
                twenty_five-=3;
            }else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
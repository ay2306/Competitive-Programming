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

class BinaryCalculator{
public:
    int minimumSteps(int a,int b){
        if(b == a){
            // cout << "0";
            return 0;
        }
        if(b > a){
            int k = (b-a)/3;
            int p = (b-a)%3;
            k+=(2*p);
            // cout << k;
            return k;
        }else{
            int k = (a-b)/2;
            int p = (a-b)%2;
            k+=(3*p);
            // cout << k;
            return k;
        }
    
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        BinaryCalculator bc;
        cout << bc.minimumSteps(a,b);
    }
    return 0;
}
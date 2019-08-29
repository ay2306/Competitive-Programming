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
#define MAXN 1001000
using namespace std;
int main(){
    // FILE_READ
    while(1){
        double a,b,c,d,e,f,g,l;
        cin >> a >> b >> c >> d;
        // cout << a << " " << b << " " << c << " " << d << "\n";
        if(a == 0)break;
        f = (d*b)/100;
        e = 1;
        g = a;
        l = b;
        while(1){
            b = max(l - (e-1)*f,0.0);
            // cout << "B = " << b << " ";
            a -= b;
            // cout << "AFTER CLIMB: " << a;
            if(a < 0 || a > g)break;
            a+=c;
            // cout << "  AFTER DESCEND: " << a << endl;
            if(a > g)break;
            // if(a == g && b <= c)break;
            e++;
        }
        // cout << endl;
        if(a > 0){
            cout << "failure on day " << e << endl;
        }else{
            cout << "success on day " << e << endl;
        }
    }
    return 0;
}
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
    FAST
    int deg = 9;
    int a,b,c,d;
    do{
        cin >> a >> b >> c >> d;
        if(a == 0 && b == 0 && c == 0 && d == 0)break;
        int ans = 80;
        if(b <= a)ans+=((a-b));
        else{
            ans+=a;
            ans+=(40-b);
        }
        ans+=40;
        a = b;
        if(c >= a)ans+=(c-a);
        else{
            ans+=(40-a);
            ans+=c;
        }
        a = c;
        if(d <= a)ans+=((a-d));
        else{
            ans+=a;
            ans+=(40-d);
        }
        cout << ans*deg << "\n";
    }while(1);
    int ans = 720;

    return 0;
}
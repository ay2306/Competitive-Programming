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
double n,m;
double a[1010],b[1010];
double A,B;
double lfuel = 0;
double rfuel = MOD;

bool check(double f){
    // cout << rfuel << endl;
    // cout << "FUEL = " << f << endl;
    double mass = (double)m + f;
    // f -= mass/a[1];
    // for(int i = 2; i <= n; ++i){
    //     mass = m+f;
    //     // cout << mass << " ";
    //     f-=(mass/b[i]);
    //     mass = m+f;
    //     // cout << mass << "\n";
    //     f-=(mass/a[i]);
    // }
    // mass = m+f;
    // f -= mass/b[1];
    // // cout << f << endl;
    double finalMass = mass*A;
    f = finalMass - m;
    if(f >= 0)return true;
    return false;
}

int main(){
    // FILE_READ
    // FAST
    cin >> n >> m;
    A = 1;
    B = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        A*=(1 - 1/a[i]);
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        A*=(1 - 1/b[i]);
    }
    double ans = MOD;
    while(lfuel < rfuel){
        // cout << lfuel << " " << rfuel << " " ;
        double f = (lfuel + rfuel)/2;
        if(check(f)){
            ans = min(f,ans);
            rfuel = f-1;
        }else{
            lfuel = f+1;
        }
    }
    if(ans == MOD){
        cout << -1;
        return 0;
    }
    // cout << ans;
    for(double i = 1; i <= 100000000; i*=10){
        double k = (double)ans;
        double l = ans-1;
        double r = ans;
        while(l < r){
            double mid = l + (r-l)/2;
            // if(l == r)break;
            if(check(mid)){
                k = min(k,mid);
                r = mid-(1/i);
            }else{
                l = mid+(1/i);
            }
        }
        ans = k;
    }
    printf("%.10f",ans);
    return 0;
}
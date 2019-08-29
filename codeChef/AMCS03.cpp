// /*
//  ____________________________________________________________
// |                                                            |
// |                   Author: ay2306                           |
// |____________________________________________________________|

// */
// #include <bits/stdc++.h>
// #define MOD 1000000007
// #define test int t; cin>>t; while(t--)
// #define init(arr,val) memset(arr,val,sizeof(arr))
// #define loop(i,a,b) for(int i=a;i<b;i++)
// #define loopr(i,a,b) for(int i=a;i>=b;i--)
// #define loops(i,a,b,step) for(int i=a;i<b;i+=step)
// #define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PII pair<int, int>
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define D deque
// #define ST set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define MM multimap
// #define F first
// #define S second
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
// #define FILE_READ_IN freopen("input.txt","r",stdin);
// #define FILE_READ_OUT freopen("output.txt","w",stdout);
// #define MAXN 25
// using namespace std;
// int n,k;
// V<PII> arr;
// const double eps = 1e-9;

// double f(double t){
//     double mx = 1e-9;
//     double mn = 1e9;
//     loop(i,0,n){
//         double p = arr[i].F*t + arr[i].S;
//         mx = max(mx,p);
//         mn = min(mn,p);
//     }
//     return mx-mn;
// }

// void solve(){
//     cin >> n >> k;
//     arr = V<PII> (n);
//     loop(i,0,n){
//         int s,d;
//         cin >> s >> d;
//         arr[i] = mp(s,d);
//     }
//     double low = 0, high = k;
//     double ans;
//     while(high - low > eps){
//         double m1 = low + (high-low)/3;
//         double m2 = high - (high-low)/3;
//         if(f(m1) < f(m2)){high = m2;ans=m1;}
//         else {low = m1; ans = m2;}
//     }
//     printf("%.6f",f(low));
// }

// int main(){
//     int t = 1;
//     // cin >> t;
//     while(t--)solve();
//     return 0;
// }


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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

double x1,y1,x2,y2,v1,v2;
const double eps = 1e-9;

double distance(double X1, double Y1, double X2, double Y2){
    return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}

double f(double x){
    double dist_on_beach,dist_in_water;
    if(y1 < 0){
        dist_on_beach = distance(x1,y1,x,0.0);
        dist_in_water = distance(x,0.0,x2,y2);
    }else{
        dist_in_water = distance(x1,y1,x,0.0);
        dist_on_beach = distance(x,0.0,x2,y2);
    }
    return dist_in_water/v2 + dist_on_beach/v1;
}

void solve(){
    cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
    if(x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    double low = x1;
    double high = x2;
    while(high-low > eps){
        double m1 = low + (high-low)/3;
        double m2 = high - (high-low)/3;
        if(f(m1) < f(m2)){
            high = m2;
        }else{
            low = m1;
        }
    }
    printf("%.10f\n",f(low));
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}   
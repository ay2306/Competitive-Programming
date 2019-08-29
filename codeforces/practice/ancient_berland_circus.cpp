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
using namespace std;

const ll maxn = 1e5;
const double EXP = 0.001;
struct point{
    double x;
    double y;
};

double distance(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double fgcd(double a, double b){
    if(fabs(b) < EXP)return a;
    return fgcd(b,fmod(a,b));
}

int main(){
    const double pi = 2*acos(0.0);
    struct point p[3];
    for(int i = 0; i < 3; ++i){
        cin >> p[i].x >> p[i].y;
    }
    double a = distance(p[1],p[0]);
    double b = distance(p[2],p[0]);
    double c = distance(p[1],p[2]);
    double area,R,semi;
    semi = (a+b+c)/2;
    area = sqrt(semi*(semi-a)*(semi-b)*(semi-c));
    //area*R*4 = a*b*c
    R = (a*b*c)/(area*4);
    double A = 2*asin(a/(2*R)); 
    double B = 2*asin(b/(2*R)); 
    double C = 2*asin(c/(2*R)); 
    cout << A << " " << B << " " << C*(180/pi) << endl;
    C = 2*pi - (A + B);
    cout << A << " " << B << " " << C*(180/pi) << endl;
    cout << 2*pi/A << " " << 2*pi/B << " " << 2*pi/C << endl;

    double t = fgcd(A,fgcd(B,C));
    double ans = pi*R*R*sin(t);
    ans/=t;
    printf("%.10f",ans); 
    return 0;
}

(-13, -45) (-33, 51) (84,-55)

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
#define PI 3.1415926535
using namespace std;
double x,y;

double find_angle(double X, double Y){
    if(x == X)return PI/2;
    double slope = (y-Y)/(abs(x-X));
    double ans =  atan(slope);
    // printf("slope = %f, angle = %f\n",slope,ans);
    if(ans > PI/2)ans-=PI/2;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    V<double> coord(n);
    loop(i,0,n){
        cin >> coord[i];
    }
    cin >> x >> y;
    V<double> l;
    V<double> r;
    for(auto i: coord){
        if(i < x){
            l.push_back(find_angle(i,0));
        }else{
            r.push_back(find_angle(i,0));
        }
    }
    // for(auto i: l){
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for(auto i: r){
    //     cout << i << " ";
    // }
    // cout << "\n";
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int i = 0;
    int j = 0;
    double ans = 0;
    while(i < l.size() && j < r.size()){
        ans+=(PI - l[i] - r[i]);
        i++;
        j++;
    }
    if(i < l.size()){
        j = l.size()-1;
        while(i < j){
            ans+=(l[j]-l[i]);
            i++;
            j--;
        }
    }else if(j < r.size()){
        i = r.size()-1;
        while(j < i){
            ans+=(r[i]-r[j]);
            j++;
            i--;
        }
    }
    printf("%.10f\n",ans);
}

int main(){
    FILE_READ_IN
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
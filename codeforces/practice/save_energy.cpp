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
const double eps = 1e-10;

double r1,r2;

double fgcd(double a, double b){
  if(fabs(a) <= eps)return b;
  return fgcd(fmod(b,a),a);
}

bool check(double a){
  
}

int main(){
  double k,d,t;
  cin >> k >> d >> t;
  t*=2;
  auto g = fgcd(k,d);
  r1 = k/g;
  r2 = d/g;
  double low = 0;
  double high = 2000000000000000000;
  double ans = high;
  while(high - low  > eps){
    double mid = low + (high-low)/2;
    if(check(mid)){
      ans = min(ans,mid);
      high = low-1;
    }else{
      low = high + 1;
    }
  }
  printf("%.10f",ans);
  return 0;
}

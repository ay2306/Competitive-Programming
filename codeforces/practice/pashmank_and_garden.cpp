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
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        int a = y2-y1;
        if(a<-1)a*=-1;
        cout << x1+a << " " << y1 << " " << x2+a << " "<< y2;
        return 0;
    }
    if(y1 == y2){
        int a = x2-x1;
        if(a<-1)a*=-1;
        cout << x1 << " " << y1+a << " " << x2 << " "<< y2+a;
        return 0;
    }
    int a = x2-x1;
    int b = y2-y1;
    if(a<0)a*=-1;
    if(b<0)b*=-1;
    if(a!=b){
        cout << "-1";return 0;
    }
    // cout << a << endl;
    cout << x1 << " " << y2 << " " << x2  << " " << y1; 
    return 0;
}
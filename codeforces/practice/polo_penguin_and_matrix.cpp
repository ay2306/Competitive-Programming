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
    int n,m,d;
    cin >> n >> m >> d;
    int *arr = new int[m*n];
    for(int i = 0; i < m*n; ++i)cin >> arr[i];
    sort(arr,arr+(m*n));
    int comp = arr[(m*n)/2];
    int ans1 = 0,ans2 =0,ans3=0;
    int diff;
    for(int i = 0; i < m*n; ++i){
        diff = arr[i]-comp;
        if(diff<0)diff*=-1;
        if(diff%d != 0){
            cout << "-1";
            return 0;
        }
        ans1+=(diff/d);
    }
    comp = arr[((m*n)/2)+1];
    for(int i = 0; i < m*n; ++i){
        diff = arr[i]-comp;
        if(diff<0)diff*=-1;
        if(diff%d != 0){
            cout << "-1";
            return 0;
        }
        ans2+=(diff/d);
    }
    comp = arr[((m*n)/2)+1];
    for(int i = 0; i < m*n; ++i){
        diff = arr[i]-comp;
        if(diff<0)diff*=-1;
        if(diff%d != 0){
            cout << "-1";
            return 0;
        }
        ans3+=(diff/d);
    }
    cout << min(ans1,min(ans2,ans3));
    return 0;
}
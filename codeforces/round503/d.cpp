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
// ll *arr;
int cnt = 0;
ll query(ll y)
{
    cnt++;
    if(cnt > 60){
        cout << "! -1\n";
        fflush(stdout);
        exit(0);
    }
    cout<<"? "<<y<<"\n";
    fflush(stdout);
    ll t;
    cin>>t;
    return t;
    // return arr[y];
}
void cquery(int y)
{
    cout<<"! "<<y<<"\n";
    fflush(stdout);
}

int main(){
    // FILE_READ
    int n;
    cin >> n;
    // arr = new ll[n+1];
    // loop(i,1,n+1)cin >> arr[i];
    int low = 1; int high = n;
    while(low <= high){
        int mid = low + high;
        mid/=2;
        ll a = query(1LL * mid);
        int nn2 = 0;
        if(mid+n/2 > n)nn2 = mid-n/2;
        else nn2 = mid+n/2;
        ll b = query(1LL * nn2);
        if(a == b){
            cquery(mid);
            exit(0);
            // return 0;      
        }
        if(a > b){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    // cout << low << " " << high;
    cquery(-1 * 1LL);
    return 0;
}
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
int a[100005],b[100005];
int main(){
    int n,i,ans=0,last=INT_MIN;
    cin >> n;  
    for(int i = 1; i <= n; ++i)cin >> a[i] >> b[i]; 
    for(int i = 1; i <= n; ++i){
        if(a[i] - b[i] > last)last = a[i],ans++;
        else if(a[i] + b[i] < a[i+1] || i == n)last = a[i]+b[i],ans++;
        else{
            last = a[i];
        }
    }
    cout << ans;
    return 0;
}
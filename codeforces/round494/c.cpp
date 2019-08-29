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
    double mav = 0,av,sum=0;
    int n,k;
    cin >> n >> k;
    double *arr = new double[n];
    for(int i = 0; i < n; ++i)cin >> arr[i];
    for(; k <=n; ++k){
        sum = 0;
        for(int i = 0; i < k; ++i){
            sum+=arr[i];
        }
        av = (sum/double(k));
        if(av > mav)mav = av;
        for(int i = k; i < n; ++i){
            sum-=arr[i-k];
            sum+=arr[i];
            av = (sum/double(k));
            if(av > mav)mav = av;
        }
    }    
    printf("%.15f",mav);
    return 0;
}
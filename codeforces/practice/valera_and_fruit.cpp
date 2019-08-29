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
    int n,v;
    cin >> n >> v;
    ll l=0,c=0;
    int *arr = (int*)calloc(4000,sizeof(int));
    for(int i = 1; i <= n; ++i){
        int x,y;
        cin >> x >> y;
        arr[x] += y;
    }
    // cout << c<< endl;
    int ans = 0;
    for(int i = 1; i < 4000; ++i){
        if(arr[i] == 0){
            if(l > v){
                c+=v;
                l = 0;
            }else{
                c+=l;
                l = 0;
            }
        }
        if(arr[i] > 0){
            if(l > v){
                c+=v;
                l = arr[i];
            }else{
                c+=l;
                ll t = v;
                t-=l;
                if(arr[i] > t){
                    c+=t;
                    l = arr[i]-t;
                }else{
                    c+=arr[i];
                    l = 0;
                }
            
            }
        }
    }
    cout << c;
    return 0;
}
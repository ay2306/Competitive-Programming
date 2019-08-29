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

int main(){
    int n;
    cin >> n;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    int ans = 0;
    loop(i,1,n){
        if(arr[i] == 1){
            if(arr[i-1] == 2){
                ans+=3;
            }else{
                ans+=4;
            }
        }
        if(arr[i] == 2){
            if(arr[i-1] == 1){
                if(i-2 > 0 && arr[i-2] == 3)ans+=2;
            }else{
                cout << "Infinite\n";
                return 0;
            }
        }
        if(arr[i] == 3){
            if(arr[i-1] == 2){
                cout << "Infinite\n";
                return 0;
            }else{
                ans+=4;
            }
        }
    }
    cout << "Finite\n" << ans ;
  return 0;
}

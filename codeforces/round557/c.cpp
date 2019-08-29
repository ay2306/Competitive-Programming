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
    // FILE_READ_OUT
    int n,m;
    cin >> n >> m;
    V<bool> arr(n,true);
    V<int> first(n,-1);
    V<int> last(n,-1);
    loop(i,0,m){
        int a;
        cin >> a;
        a--;
        if(first[a] == -1)first[a] = i;
        last[a] = i;
        arr[a] = false;
    }
    int ans = 0;
    loop(i,0,n){
        int k = 0;
        if(arr[i]){
            if(i == 0)k+=2;
            else if(i == n-1)k+=2;
            else k+=3;
        }
        else{
            if(i > 0 &&  last[i-1] < first[i])k++;
            if(i+1 < n && last[i+1] < first[i])k++;
        }
        ans+=k;
        // printf("i = %d, cont = %d\n",i,k);
    }
    cout << ans;
  return 0;
}


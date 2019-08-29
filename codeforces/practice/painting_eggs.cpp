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
#define V vector
#define L list
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

int main(){
    int n;
    cin >> n;
    string ans (n,' ');
    // PII *arr = new PII[n];
    int *arr = new int[n];
    loop(i,0,n){
        int a,b;
        cin >> a >> b;
        arr[i] = a;
        // arr[i] = mp(a,i+1);
    }
    // sort(arr,arr+n);
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++){
        if(abs(arr[i]+a-b) > 500){
            b+=(1000-arr[i]);
            ans[i] = 'G';
        }else{
            a+=arr[i];
            ans[i] = 'A';
        }
    }
    cout << ans;
    return 0;
}
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
    int *arr = new int[n];
    loop(i,0,n)cin >> arr[i];
    string a;
    cin >> a;
    int i = 0;
    int j = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == '1'){
            j = i;
            while(j < a.size() && a[j] == '1')++j;
            sort(arr+i,arr+j+1);
            i = j;
        }
    }
    for(int i = 1; i < n; ++i){
        if(arr[i] < arr[i-1]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
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

int main(){
    int n;
    cin >> n;
    V<string> arr;
    loop(i,0,n){
        string a;
        cin >> a;
        arr.pb(a);
    }
    char a = arr[0][0];
    char b = arr[0][1];
    if(a == b){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i+j+1 == n || i == j){
                if(arr[i][j] != a){
                    // cout << a << " " << arr[i][j] << " " << i << " " << j << endl;
                    cout << "NO";
                    return 0;
                }
            }else{
                if(arr[i][j] != b){
                    // cout << b << " " << arr[i][j] << " " << i << " " << j << endl;
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    return 0;
}
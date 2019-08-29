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
#define MAXN 25
using namespace std;
int n, m;
int visited[60][60];
int empty[60][60];
int arr[60][60];

bool valid(int a,int b){
    if(a >= 0 && a < n && b >= 0 && b < m && !empty[a][b]){empty[a][b] = 1; return true;}
    return false;
}

void do_something(int i, int j){
    while(1){
        visited[i][j] = 1;
        // for(int l = 0; l < n; ++l){
        //     for(int k = 0; k < m; ++k){
        //         cout << empty[l][k] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        if(valid(i+1,j)){
            arr[i][j] = 1;
            i++;
        }
        else if(valid(i,j+1)){
            arr[i][j] = 1;
            j++;
        }
        else if(valid(i-1,j)){
            arr[i][j] = 1;
            i--;
        }
        else if(valid(i,j-1)){
            arr[i][j] = 1;
            j--;
        }else{
            break;
        }
    }
}

void solve(){
    cin >> n >> m;
    if(n%2 == 0 || m%2 == 0){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
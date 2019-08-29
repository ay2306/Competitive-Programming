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
int mx = 0;
bool maxSet = false;

bool check(V<V<char>> &arr){
    loop(i,0,arr.size()){
        loop(j,0,arr.size()){
            loop(i1,i+1,arr.size()){
                loop(j1,j+1,arr.size()){
                    if(arr[i][j] == 'O' && arr[i][j1] == 'O' && arr[i1][j1] == 'O' && arr[i1][j] == 'O')return false;
                }
            }
        }
    }
    return true;
}


int main(){
    // FILE_READ_OUT
    int n;
    cin >> n;
    V<V<char>> arr(n,V<char> (n,'.'));
    loop(i,0,n){
        loops(j,i,n,2){
            arr[i][j] = 'O';
        }
    }
    loop(i,0,n){
        loop(j,0,n){
            printf("%2c ",arr[i][j]);
        }
        printf("\n");
    }
    if(check(arr)){
        printf("LOGICALLY CORRECT\n");
    }
    else{
        printf("LOGICALLY INCORRECT\n");
    }
    return 0;
}
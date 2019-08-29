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

int *arr;

int root(int x){
    while(x != arr[x]){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void UNION(int a, int b){
    int p = root(a);
    int q = root(b);
    arr[p] = q;
}

int main(){
    int n;
    cin >> n;
    arr = new int[n+1];
    for(int i = 1; i <= n; ++i)arr[i] = i;
    int q;
    cin >> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0){
            UNION(c,b);
            // for(int i = 1; i <= n; ++i)cout << arr[i] << " ";
            // cout << endl;
        }else{
            if(root(b) == root(c)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
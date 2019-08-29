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
V<int> parent;
V<int> Rank;

int getParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void solve(){
    int n;
    cin >> n;
    parent = V<int>(n+1,0);
    Rank = V<int>(n+1,0);
    loop(i,1,n+1)parent[i] = i;
    V<int> arr(n+1);
    loop(i,1,n+1)cin >> arr[i];
    int q;
    cin >> q;
    while(q--){
        int t,a,b;
        cin >> t;
        if(t == 0){
            cin >> a >> b;
            int parent_a = getParent(a);
            int parent_b = getParent(b);
            if(parent_a == parent_b){
                cout << "Invalid query!\n";
            }else{
                if(arr[parent_a] > arr[parent_b]){
                    parent[parent_b] = parent_a;
                }
                else if(arr[parent_a] < arr[parent_b]){
                    parent[parent_a] = parent_b;
                }
            }
        }else{
            cin >> a;
            cout << getParent(a) << "\n";
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
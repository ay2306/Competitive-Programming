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

void solve(){
    unordered_map<int,set<int> > m;
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    m[arr[arr[1]]] = set<int> ();
    m[arr[arr[1]]].insert(arr[1]);
    for(int i = 2; i <= n; ++i){
        if(m.find(arr[arr[i]]) == m.end()){
            m[arr[arr[i]]] = set<int> ();
        }
        m[arr[arr[i]]].insert(arr[i]);
    }
    for(auto i: m){
        // printf("%d : ",i.first);
        // for(auto j: i.second){
        //     printf("%d, ",j);
        // }
        // printf("\n");
        if(i.second.size() > 1){
            printf("Truly Happy\n");
            return;
        }
    }

    printf("Poor Chef\n");
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
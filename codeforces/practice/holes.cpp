
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
using namespace std;
const int MAXN = 1e5 + 10;
const int SIZE = 450;
int n;
int values[MAXN];
P<int/*where*/,int/*steps*/> jump[MAXN];

void evaluate(int bucket){
    int high = min(n-1, SIZE*bucket+SIZE-1),stop = bucket*SIZE;
    for(int j = high; j >= stop; j--){
        if(j+values[j] > high)jump[j]=mp(j,0);
        else jump[j] = mp(jump[j+values[j]].first, jump[j+values[j]].second + 1);
    }
}

void query(int where){
    int ans = 0;
    while(where < n){
        ans = ans+jump[where].second;
        where = jump[where].first;
        ans++;
        if(where + values[where] >= n){
            cout << where+1 << " " << ans << endl;
            return;
        }
        where = where +values[where];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    loop(i,0,n)cin >> values[i];
    for(int i = 0; i*SIZE < n; ++i){
        evaluate(i);
    }
    loop(i,1,m+1){
        int t;
        cin >> t;
        if(t == 0){
            int a,b;
            cin >> a >> b;
            a--;
            values[a]=b;
            evaluate(a/SIZE);
        }else{
            int a;
            cin >> a;
            a--;
            query(a);
        }
    }
    return 0;
}
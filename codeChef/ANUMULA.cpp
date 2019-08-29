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
#define N 16
using namespace std;

int b[1<<N], c[1<<N];
int a[N];

void solve(){
    int n;
    cin >> n;
    int m = (1 << n);
    loop(i,0,m){
        cin >> b[i];
    }
    sort(b,b+m);
    multiset<int> s;
    int ptr = 0;
    int fptr = 0;
    for(int i = 1; i < m; ++i){
        int expected = -1;
        if(!s.empty()){
            expected = *s.begin();
        }
        if(b[i] == expected){
            s.erase(s.begin());
        }else{
            a[fptr] = b[i];
            int tptr = ptr;
            for(int j = 0; j < tptr ; ++j){
                c[ptr] = c[j] + a[fptr];
                s.insert(c[ptr]);
                ptr++;
            }
            c[ptr++] = a[fptr];
            fptr++;
        }
    }
    for(int i = 0; i < fptr; ++i)cout << a[i] << " ";
    cout << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
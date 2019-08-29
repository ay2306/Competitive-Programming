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
#define MAXN 1001000
using namespace std;

struct die{
    int top;
    int bottom;
    int north;
    int west;
    int east;
    int south;
}current;

void change(string a){

    if(a[0] == 'n'){
        int e,f,g,h;
        e = current.top;
        f = current.north;
        g = current.bottom;
        h = current.south;
        current.top = h;
        current.north = e;
        current.bottom = f;
        current.south = g;
    }
    if(a[0] == 's'){
        int e,f,g,h;
        e = current.top;
        f = current.north;
        g = current.bottom;
        h = current.south;
        current.top = f;
        current.north = g;
        current.bottom = h;
        current.south = e;
    }
    if(a[0] == 'e'){
        int e,f,g,h;
        e = current.top;
        f = current.west;
        g = current.bottom;
        h = current.east;
        current.top = f;
        current.west = g;
        current.bottom = h;
        current.east = e;
    }
    if(a[0] == 'w'){
        int e,f,g,h;
        e = current.top;
        f = current.west;
        g = current.bottom;
        h = current.east;
        current.top = h;
        current.west = e;
        current.bottom = f;
        current.east = g;
    }
}

int main(){
    // FILE_READ
    while(1){
        int n;
        cin >> n;
        if(n == 0)break;
        current.top = 1;
        current.bottom = 6;
        current.north = 2;
        current.south = 5;
        current.west = 3;
        current.east = 4;
        while(n--){
            string a;
            cin >> a;
            change(a);
        }
        cout << current.top << "\n";
    }
    return 0;
}
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

string current = "north";

void change(string a){
    if(a[0] == 'l'){
        switch(current[0]){
            case 'n': current = "west"; break;
            case 'w': current = "south"; break;
            case 's': current = "east"; break;
            case 'e': current = "north"; break;
        }
    }
    else if(a[0] == 'r'){
        switch(current[0]){
            case 'n': current = "east"; break;
            case 'w': current = "north"; break;
            case 's': current = "west"; break;
            case 'e': current = "south"; break;
        }
    }
    else if(a[0] == 'b'){
        switch(current[0]){
            case 'n': current = "south"; break;
            case 'w': current = "east"; break;
            case 's': current = "north"; break;
            case 'e': current = "west"; break;
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        change(a);
    }
    cout << current;
   return 0;
}
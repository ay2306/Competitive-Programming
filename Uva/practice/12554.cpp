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
int main(){
    // FILE_READ
    int n;
    cin >> n;
    V<string> names(n),words(16);
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        names[i] = a;
    }
    words[0] = "Happy";
    words[1] = "birthday";
    words[2] = "to";
    words[3] = "you";
    words[4] = "Happy";
    words[5] = "birthday";
    words[6] = "to";
    words[7] = "you";
    words[8] = "Happy";
    words[9] = "birthday";
    words[10] = "to";
    words[11] = "Rujia";
    words[12] = "Happy";
    words[13] = "birthday";
    words[14] = "to";
    words[15] = "you";
    int p = 0;
    int i = 0;
    int j = 0;
    for(int k = 0; k < n; ++k){
        cout << names[i%n] << ": " << words[j%16] << endl;
        ++j;
        ++i;
    }
    while(j%16 != 0){
        cout << names[i%n] << ": " << words[j%16] << endl;
        ++j;
        ++i;
    }
    return 0;
}
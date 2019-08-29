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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    vector<string> a;
    for(int i = 0; i < 4; ++i){
        string s;
        cin >> s;
        a.pb(s);
    }
    for(int i = 0; i + 1 < 4; ++i){
        for(int j = 0; j + 1 < 4; ++j){
            int b = 0;
            int w = 0;
            if(a[i][j] == '#')b++;
            if(a[i][j] == '.')w++;
            if(a[i][j+1] == '#')b++;
            if(a[i][j+1] == '.')w++;
            if(a[i+1][j] == '#')b++;
            if(a[i+1][j] == '.')w++;
            if(a[i+1][j+1] == '#')b++;
            if(a[i+1][j+1] == '.')w++;
            if(b==3 || b == 4 || w == 3 || w == 4){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
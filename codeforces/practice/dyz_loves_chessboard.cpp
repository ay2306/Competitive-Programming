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
    // freopen("output.txt","w+",stdout);
    int n,m;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        b.pb(s);
        s="";
        for(int j = 0; j < m; ++j)s+=".";
        a.pb(s);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == '-')continue;
            char up = ' ';
            char left = ' ';
            if(i-1 >= 0){
                if(a[i-1][j] == 'B')up = 'B';
                if(a[i-1][j] == 'W')up = 'W';
            }
            if(j-1 >= 0){
                if(a[i][j-1] == 'B')left = 'B';
                if(a[i][j-1] == 'W')left = 'W';
            }
            if(up == 'B' || left == 'B')a[i][j] = 'W';
            else if((up == 'B' || left =='B') && i>0 && j > 0)a[i][j]='.';
            else a[i][j] = 'B';
        }
    }
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(b[i][j]=='-')cout << "-";
            else cout << a[i][j];
        }
        if(i+1!=n)cout << endl;
    }
    return 0;
}
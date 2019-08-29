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
int arr[110][110];
bool tmp[110][110];
int n,m;

void moveRight(int i){
    int k = 0,j;
    for(int j = 1; j <= m; ++j)if(arr[i][j])k++;
    for(int j = m; j > 0; --k,j--){if(k > 0)arr[i][j]=1;else arr[i][j] = 0;}
}

void moveLeft(int i){
    int k = 0;
    for(int j = 1; j <= m; ++j)if(arr[i][j])k++;
    for(int j = 1; j <= m; --k,j++){if(k > 0)arr[i][j]=1;else arr[i][j] = 0;}
}

void moveUp(int i){
    int k = 0;
    for(int j = 1; j <= n; ++j)if(arr[j][i])k++;
    for(int j = 1; j <= n; --k,j++){if(k > 0)arr[j][i]=1;else arr[j][i] = 0;}
}

void moveDown(int i){
    int k = 0;
    for(int j = 1; j <= n; ++j)if(arr[j][i])k++;
    for(int j = n; j > 0; --k,j--){if(k > 0)arr[j][i]=1;else arr[j][i] = 0;}
}

void solve(){
    cin >> n >> m;
    /*
     * 
     *  INPUT
     * 
     */
    for(int i = 1; i <= n; ++i){
        string a;
        cin >> a;
        for(int j = 1; j <= m; ++j){
            arr[i][j] = (a[j-1] == '1');
        }
    }

    string t;
    cin >> t;
    string d = "";
    d+=t[0];
    /*
    *
    * REMOVING DUPLICATE MOVES FROM t AND STORING THEM IN D
    *    
    */
    for(int i = 1; i < t.length(); ++i){
        if((t[i] == 'U' || t[i] == 'D') && (d[d.length()-1] == 'R' || d[d.length()-1] == 'L'))d+=t[i];
        if((t[i] == 'L' || t[i] == 'R') && (d[d.length()-1] == 'D' || d[d.length()-1] == 'U'))d+=t[i];
        if((t[i] == 'U' || t[i] == 'D') && (d[d.length()-1] == 'U' || d[d.length()-1] == 'D'))d[d.length()-1]=t[i];
        if((t[i] == 'L' || t[i] == 'R') && (d[d.length()-1] == 'L' || d[d.length()-1] == 'R'))d[d.length()-1]=t[i];
    }
    // cout << d << endl;
    /*
    *
    *  MAKING MOVES AS INTRUCTED
    * 
    */
    for(int k = 0; k < d.length(); ++k){
        switch(d[k]){
            case 'L':
                for(int i = 1; i <= n; ++i)moveLeft(i);
                break;
            case 'R':
                for(int i = 1; i <= n; ++i)moveRight(i);
                break;
            case 'U':
                for(int i = 1; i <= m; ++i)moveUp(i);
                break;
            case 'D':
                for(int i = 1; i <= m; ++i)moveDown(i);
                break;
            
        }
    }    
    /*
    *
    *   OUTPUT THE CALCULATED ARRAY 
    * 
    */
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; ++j)cout << arr[i][j];
        cout << endl;
    }    
}
int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
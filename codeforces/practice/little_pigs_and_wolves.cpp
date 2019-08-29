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

int checkPigAround(int i, int j, V<string> v){
    int c = 0;
    int n = v.size();
    int m = v[0].length();
    if(i+1 < n)if(v[i+1][j] == 'P')c++;
    if(i-1 >= 0)if(v[i-1][j] == 'P')c++;
    if(j+1 < m)if(v[i][j+1] == 'P')c++;
    if(j-1 >= 0)if(v[i][j-1] == 'P')c++;
    return c;
}

int checkWolfAround(int i, int j, V<string> v){
    int c = 0;
    int n = v.size();
    int m = v[0].length();
    if(i+1 < n)if(v[i+1][j] == 'W')c++;
    if(i-1 >= 0)if(v[i-1][j] == 'W')c++;
    if(j+1 < m)if(v[i][j+1] == 'W')c++;
    if(j-1 >= 0)if(v[i][j-1] == 'W')c++;
    return c;
}

int main(){
    int n,m;
    cin >> n >> m;
    V<string> v;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        v.pb(str);
    }   
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] == 'W'){
                int i_least = -1,j_least=-1,c = 20000;
                // cout << i << " " << j<<endl;
                if(i+1 < n && v[i+1][j] == 'P'){
                    // cout << "PELLO\n";
                    int k = checkWolfAround(i+1,j,v);
                    // cout << k << endl;
                    if(k < c && k!=0){
                        i_least = i+1;
                        j_least = j;
                    }
                }
                if(i-1 >= 0 && v[i-1][j] == 'P'){
                    int k = checkWolfAround(i-1,j,v);
                    if(k < c && k!=0){
                        i_least = i-1;
                        j_least = j;
                    }
                }
                if(j+1 < m && v[i][j+1] == 'P'){
                    int k = checkWolfAround(i,j+1,v);
                    if(k < c && k!=0){
                        i_least = i;
                        j_least = j+1;
                    }
                }
                if(j-1 >= 0 && v[i][j-1] == 'P'){
                    int k = checkWolfAround(i,j-1,v);
                    if(k < c && k!=0){
                        i_least = i;
                        j_least = j-1;
                    }
                }
                if(i_least != -1 && j_least!=-1){
                    v[i_least][j_least]='.';
                    v[i][j] = '.';
                    // for(int k = 0; k < n; ++k){
                    //     cout << v[k] << endl;
                    // }
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
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
#define MAXN 25
using namespace std;

struct p{
    ll c;
    char path;
    bool operator< (const p& rhs){
        if(c < rhs.c)return true;
        return false;
    }
};
struct p1{
    ll t,f;
};
p1 arr[1010][1010];
p dp2[1010][1010];
p dp5[1010][1010];


int main(){
    FAST
    // FILE_READ_IN
    int n;
    int z = 0;
    int zi,zj;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ll a;
            arr[i][j].t = 0;
            arr[i][j].f = 0;
            cin >> a;
            if(a == 0){
                z=1;
                zi = i;
                zj = j;   
            }
            while(a > 0 && a%2 == 0){
                arr[i][j].t++;
                a/=2;
            }
            while(a > 0 && a%5 == 0){
                arr[i][j].f++;
                a/=5;
            }
        }
    }
    dp2[0][0].path = ' ';
    dp5[0][0].path = ' ';
    dp2[0][0].c = arr[0][0].t;
    dp5[0][0].c = arr[0][0].f;
    for(int i = 1; i < n; ++i){
        dp2[i][0] = dp2[i-1][0];
        dp2[i][0].c+=arr[i][0].t;
        dp2[i][0].path='D';
        dp2[0][i] = dp2[0][i-1];
        dp2[0][i].c+=arr[0][i].t;
        dp2[0][i].path='R';
        
        dp5[i][0] = dp5[i-1][0];
        dp5[i][0].c+=arr[i][0].f;
        dp5[i][0].path='D';
        dp5[0][i] = dp5[0][i-1];
        dp5[0][i].c+=arr[0][i].f;
        dp5[0][i].path='R';
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            if(dp2[i-1][j] < dp2[i][j-1]){
                dp2[i][j] = dp2[i-1][j];
                dp2[i][j].path='D';
            }else{
                dp2[i][j] = dp2[i][j-1];
                dp2[i][j].path='R';
            }
            dp2[i][j].c+=arr[i][j].t;

            if(dp5[i-1][j] < dp5[i][j-1]){
                dp5[i][j] = dp5[i-1][j];
                dp5[i][j].path='D';
            }else{
                dp5[i][j] = dp5[i][j-1];
                dp5[i][j].path='R';
            }
            dp5[i][j].c+=arr[i][j].f;
        }
    }
    p ans;
    if(dp2[n-1][n-1] < dp5[n-1][n-1]){
        if(z && dp2[n-1][n-1].c > 1){
            cout << 1 << "\n";
            string path = "";
            for(int i = 1; i <= zi; ++i)path+="D";
            for(int j = 1; j < n; ++j)path+="R";
            for(int i = zi+1; i < n; ++i)path+="D";
            cout << path;
            return 0;
        }
        int i = n-1;
        int j = n-1;
        string path = "";
        while(i > 0 || j > 0){
            path+=(dp2[i][j].path);
            if(dp2[i][j].path == 'R')j--;
            else i--;
        }
        reverse(path.begin(),path.end());
        cout << dp2[n-1][n-1].c << "\n" << path;
    }
    else{
        if(z && dp5[n-1][n-1].c > 1){
            cout << 1 << "\n";
            string path = "";
            for(int i = 1; i <= zi; ++i)path+="D";
            for(int j = 1; j < n; ++j)path+="R";
            for(int i = zi+1; i < n; ++i)path+="D";
            cout << path;
            return 0;
        }
        int i = n-1;
        int j = n-1;
        string path = "";
        while(i > 0 || j > 0){
            path+=(dp5[i][j].path);
            if(dp5[i][j].path == 'R')j--;
            else i--;
        }
        reverse(path.begin(),path.end());
        cout << dp5[n-1][n-1].c << "\n" << path;
    }
    // auto ans = min(dp2[n-1][n-1],dp5[n-1][n-1]);
    // cout << dp2[n-1][n-1].c << " " << dp2[n-1][n-1].path << "\n";
    // cout << dp5[n-1][n-1].c << " " << dp5[n-1][n-1].path << "\n";
}
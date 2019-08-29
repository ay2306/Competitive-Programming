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
int t,f;

void solve(){
    string ab = "ABCDE";
    unordered_map<string,bool> m;
    do{
        m[ab] = true;
    }while(next_permutation(ab.begin(),ab.end()));
    for(int i = 1; i <= 82; ++i){
        string p_this = "";
        int state = (1 + 2 + 4 + 8 + 16);
        for(int j = 1; j <= 4; ++j){
            cout << (i-1)*5 + j << "\n";
            fflush(stdout);
            char a;
            cin >> a;
            if(a == 'N')exit(0);
            p_this+=a;
            if(a == 'A')state^=1;
            if(a == 'B')state^=2;
            if(a == 'C')state^=4;
            if(a == 'D')state^=8;
            if(a == 'E')state^=16;
        }
        if(state == 1)p_this+="A";
        if(state == 2)p_this+="B";
        if(state == 4)p_this+="C";
        if(state == 8)p_this+="D";
        if(state == 16)p_this+="E";
        m[p_this] = false;
    }
    for(int i = 84; i <= 119; ++i){
        string p_this = "";
        int state = (1 + 2 + 4 + 8 + 16);
        for(int j = 1; j <= 4; ++j){
            cout << (i-1)*5 + j << "\n";
            fflush(stdout);
            char a;
            cin >> a;
            if(a == 'N')exit(0);
            p_this+=a;
            if(a == 'A')state^=1;
            if(a == 'B')state^=2;
            if(a == 'C')state^=4;
            if(a == 'D')state^=8;
            if(a == 'E')state^=16;
        }
        if(state == 1)p_this+="A";
        if(state == 2)p_this+="B";
        if(state == 4)p_this+="C";
        if(state == 8)p_this+="D";
        if(state == 16)p_this+="E";
        m[p_this] = false;
    }
    string a = "";
    string b = "";
    for(auto &i: m){
        if(i.S == true){
            if(a == "")a = i.F;
            else{
                b = i.F;
                break;
            }
        }
    }
    for(int i = 1; i<=5; ++i){
        cout << 82*5 + i << "\n";
        fflush(stdout);
        char c;
        cin >> c;
        if(c == a[i-1] && c != b[i-1]){
            cout << b << "\n";
            fflush(stdout);
            char v;
            cin >> v;
            if(v == 'Y')return;
            else exit(0);
        }
        if(c == b[i-1] && c != a[i-1]){
            cout << a << "\n";
            fflush(stdout);
            char v;
            cin >> v;
            if(v == 'Y')return;
            else exit(0);
        }
    }
}

int main(){
    // string ab = "ABC";
    // do{
    //     cout << ab << "\n"; 
    // }while(next_permutation(ab.begin(),ab.end()));
 
    cin >> t >> f;
    loop(i,1,t+1){
        solve();
    }
    return 0;
}
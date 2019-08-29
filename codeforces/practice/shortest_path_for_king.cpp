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

int main(){
    string a,b;
    cin >> a >> b;
    int x = a[0]-'a';
    int y = a[1]-'0';
    int x1 = b[0]-'a';
    int y1 = b[1]-'0';
    vector<string> ans;
    int an = min(abs(x-x1),abs(y-y1));
    if(an != 0){
        string p = "";
        if(x > x1)p+="L";
        else p+="R";
        if(y > y1)p+="D";
        else p+="U";
        loop(i,0,an)ans.pb(p);
    }
    if(abs(x-x1) < abs(y-y1)){
        if(y > y1){
            // cout << "A\n";
            y-=abs(x-x1);
            // cout << y << "\n";
            while(y > y1){
                ans.pb("D");
                y--;
            }
        }else{
            // cout << "B\n";
            y+=abs(x-x1);
            // cout << y << "\n";
            while(y < y1){
                ans.pb("U");
                y++;
            }
        }
    }else{
        if(x > x1){
            // cout << "C\n";
            x-=abs(y-y1);
            // cout << x << "\n";
            while(x > x1){
                ans.pb("L");
                x--;
            }
        }else{
            // cout << "D\n";
            x+=abs(y-y1);
            // cout << x << "\n";
            while(x < x1){
                ans.pb("R");
                x++;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto i: ans)cout << i << "\n";
    return 0;
}
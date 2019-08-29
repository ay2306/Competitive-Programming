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
 
int n;
int c;
void game0(){
    vector<string> arr(n,"");
    loop(i,0,n)cin >> arr[i];
    vector<int> p(n,0);
    while(1){
        bool made_move = false;
        if(c == 0){
            for(int i = 0; i < n; ++i){
                if(p[i] < arr[i].size() && arr[i][p[i]] == '0'){
                    made_move = true;
                    while(p[i] < arr[i].size() && arr[i][p[i]] == '0')p[i]++;
                    break;
                }
            }
            if(!made_move){
                cout << "Dee\n";
                return;
            }
            c = 1-c;
        }else{
            for(int i = 0; i < n; ++i){
                if(p[i] < arr[i].size() && arr[i][p[i]] == '1'){
                    made_move = true;
                    while(p[i] < arr[i].size() && arr[i][p[i]] == '1')p[i]++;
                    break;
                }
            }
            if(!made_move){
                cout << "Dum\n";
                return;
            }
            c = 1-c;
        }
    }
}

void solve(){
    cin >> n;
    string s;
    cin >> s;
    if(s == "Dee"){
        c = 0;
    }else{
        c = 1;
    }
        game0();
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
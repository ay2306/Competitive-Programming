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
unordered_map<ll,bool> m;
// unordered_map<ll,string> m1;

int cal(ll a){
    if(m.count(a) != 0)return m[a];
    if(a == 0)return false;
    if(a == 1)return true;
    if(a%2 == 0){
        m[a] = !cal(a/2);
    }else{
        m[a] = (!cal(a-1) | !cal(a+1));
    }
    return m[a];
}

void solve(){
    ll n;
    cin >> n;
    bool w = cal(n);
    if(!w){
        cout << "Lose" << "\n";
        fflush(stdout);
        string in;
        cin >> in;
        if(in == "WA"){
            return;
        }
    }else{
        cout << "Win" << endl;
        fflush(stdout);
        while(n){
            if(n%2 == 0){
                cout << "/2" << "\n";
                fflush(stdout);
                n/=2;
            }
            else if(!cal(n-1)){
                cout << "-1" << "\n";
                fflush(stdout);
            }else{
                cout << "+1" << "\n";
                fflush(stdout);
            }
            string in;
            cin >> in;
            if(in[0] == 'W')return;
            else if(in[0] == 'G')break;
            else if(in[0] == '/')n/=2;
            else if(in[0] == '-')n--;
            else if(in[0] == '+')n++;
        }
    }
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
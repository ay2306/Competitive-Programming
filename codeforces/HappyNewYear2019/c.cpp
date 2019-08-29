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
    map<pair<int,int>,int > m;
    int n;
    cin >> n;
    int ans = 0;    
    loop(i,0,n){
        int a = 0;
        int b = 0;
        string s;
        cin >> s;
        for(auto j: s){
            if(j == '(')a++;
            if(j == ')'){
                if(a == 0)b++;
                else a--;
            }
        }
        pair<int,int> p = make_pair(a,b);
        pair<int,int> pd = make_pair(b,a);
        if(b == 0){
            if(m[mp(0,a)] !=0){
                ans++;
                m[mp(0,a)]--;
            }else{
                m[mp(a,0)]++;
            }
        }else if(a == 0){
            if(m[mp(b,0)] !=0){
                ans++;
                m[mp(b,0)]--;
            }else{
                m[mp(0,b)]++;
            }
        }
    }
    cout << ans;
    return 0;
}
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
string a;
ll ans;
map<string,int> m;
int f[9];
void subs(string b, int ind){
    cout << b << endl;
    if(ind == a.length())return;
    if(m[b] == 0 && b[0]!='0'){
        m[b]++;
        int flag = 1;
        int f1[9] = {0};
        for(int i = 0; i < b.length(); ++i)f1[b[i]-'0']++;
        for(int i = 0; i < 10; ++i){
            if(!((f[i]==0)^(f1[i]==0))){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    subs(b,ind+1);
    subs(b+a[ind],ind+1);
}

int main(){
    cin >> a;
    for(int i = 0; i < a.length(); ++i){
        f[a[i]-'0']++;
    }
    subs("",0);
    cout << ans;
    return 0;
}
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
#define MAXN 1001000
using namespace std;

int main(){
    // FILE_READ
    string a = "12345678";
    while(1){
        string g = "";
        int n,l;
        cin >> n >> l;
        if(n == 0 && l == 0)return 0;
        for(int i = 0; i < n; ++i)g+=a[i];
        vector<pair<PII,int> > arr;
        while(l--){
            int x,y,z;
            cin >> x >> y >> z;
            x++;
            y++;
            arr.pb(mp(mp(x,y),z));
        }
        int ans = 0;
        do{
            bool f = true;
            map<int,int> m;
            for(int i = 0; i < n; ++i)m[int(g[i]-'0')]=i;
            for(auto i:arr){
                if(i.second > 0){
                    if(abs(m[i.first.first]-m[i.first.second]) > i.second)f=false;
                }
                else if(i.second < 0){
                    if(abs(m[i.first.first]-m[i.first.second]) < abs(i.second))f=false;
                }
            }
            if(f)ans++;
        }while(next_permutation(g.begin(),g.end()));
        cout << ans << "\n";
    }
    return 0;
}
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

int main(){
    int n,m;
    cin >> n >> m;
    int* a = (int*)calloc(n+1,sizeof(int));
    for(int i = 0; i < m; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        P<int,bool> p[4];
        p[1] = mp(1,true);
        p[2] = mp(2,true);
        p[3] = mp(3,true);
        p[a[x]].second = false;
        p[a[y]].second = false;
        p[a[z]].second = false;
        if(a[x] == 0){
            for(int j = 1; j < 4; ++j){
                if(p[j].second){
                    a[x] = p[j].first;
                    p[j].second = false;
                    break;
                }
            }
        }
        if(a[y] == 0){
            for(int j = 1; j < 4; ++j){
                if(p[j].second){
                    a[y] = p[j].first;
                    p[j].second = false;
                    break;
                }
            }
        }
        if(a[z] == 0){
            for(int j = 1; j < 4; ++j){
                if(p[j].second){
                    a[z] = p[j].first;
                    p[j].second = false;
                    break;
                }
            }
        }
    }   
    for(int i = 1; i <= n; ++i)cout << a[i] << " ";
    return 0;
}
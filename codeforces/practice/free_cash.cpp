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
    M<int,M<int,int> > m;
    int n;
    cin >> n;
    int mx = 1;
    for(int i = 0; i < n; ++i){
        int h,mi;
        cin >> h >> mi;
        if(m.count(h) == 0){
            M<int,int> me;
            me.insert(mp(mi,1));
            m.insert(mp(h,me));
        }else{
            if(m.find(h)->second.count(mi) == 0){
                m.find(h)->second.insert(mp(mi,1));
            }else{
                int a = ++(m.find(h)->second.find(mi)->second);
                if(a>mx)mx=a;
            }
        }
    }
    cout << mx;
    return 0;
}
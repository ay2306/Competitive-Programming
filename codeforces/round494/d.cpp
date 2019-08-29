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
    bool a[100] = {0};
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        ull d = 0;
        ull p = 0;
        ull c = 0;
        cin >> d;
        while(d){
            d/=2;
            ++c;
        }
        a[c-1] = true;
    }
    while(q--){
        int i = 0;
        int c = 0;
        int flag = 1;
        ull p;
        cin >> p;
        while(p){
            // ull p
            if(p % 2 == 1){
                if(!a[i]){
                    flag = 0;
                    cout << "-1\n";
                    break;
                }else{
                    c++;
                }
                // if(p == 0)break;
            }
            p = (p>>1);
            i++;
        }
        if(flag)cout << c << endl;
    }
    return 0;
}
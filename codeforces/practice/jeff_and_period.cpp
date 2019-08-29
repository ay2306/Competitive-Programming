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
    M<int,V<int> > m;
    int n;
    cin >> n;
    for(int i=0,a; i < n; ++i){
        cin >> a;
        if(m.count(a) == 0){
            V<int> v;
            v.pb(i);
            m.insert(mp(a,v));
        }else{
            m.find(a)->second.pb(i);
        }
    }
    V<PII> ans;
    for(M<int,V<int> >::IT i = m.begin(); i != m.end(); ++i){
        if(i->second.size() == 1){
            ans.pb(mp(i->first,0));
        }else if(i->second.size() ==2){
            ans.pb(mp(i->first,(i->second[1]-i->second[0])));
        }
        else{
            bool pos = true;
            V<int> v = i->second;
            for(int j = 2; j < v.size(); ++j){
                if(v[j-1]-v[j-2] != v[j]-v[j-1]){
                    pos = false;
                    break;
                }
            }
            if(pos){
                ans.pb(mp(i->first,v[1]-v[0]));
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
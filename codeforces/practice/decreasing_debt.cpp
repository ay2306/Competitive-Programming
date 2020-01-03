#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m;
unordered_map<int,ll> give[N];
unordered_map<int,ll> take[N];

void printMap(){
    printf("PRINTING MAP RIGHT NOW:\n");
    loop(i,0,n){
        for(auto j: give[i]){
            printf("Node %d has to give node %d => amount = %lld\n",i+1,j.first+1,j.second);
        }
    }
}

int main(){
    // FILE_READ_OUT
    cin >> n >> m;
   loop(i,0,m){
       int a,b;
       ll c;
       cin >> a >> b >> c;
       a--;
       b--;
       give[a][b]+=c;
       take[b][a]+=c;
   }
   for(int i = 0; i < n; ++i){
       auto t = take[i].begin();
       auto g = give[i].begin();
       list<pair<unordered_map<int,ll>::iterator,int>> to_del_take, to_del_give;
    //    printf("Talking about node = %d\n",i+1);
       while(t != take[i].end() && g != give[i].end()){
        //    printf("We gave node = %d, amount = %lld\n",t->first+1,t->second);
        //    printf("We owes node = %d, amount = %lld\n",g->first+1,g->second);
           if(t->first == g->first){
                ll val1 = g->second;
                ll val2 = t->second;
               if(g->second > t->second){
                   g->second-=val2;
                   take[t->first][i]-=val2;
                   to_del_take.pb(mp(t,i));
                   to_del_give.pb(mp(give[t->first].find(i),t->first));
                   t++;
               }else if(val1 == val2){
                   to_del_take.pb(mp(t,i));
                   to_del_give.pb(mp(give[t->first].find(i),t->first));
                   to_del_give.pb(mp(g,i));
                   to_del_take.pb(mp(take[t->first].find(i),t->first));
                   g++;
                   t++;
               }else{
                   t->second-=val1;
                   give[t->first][i]-=val1;
                   to_del_give.pb(mp(t,i));
                   to_del_take.pb(mp(give[t->first].find(i),t->first));
                   g++;
               }
           }else{
            if(t->second >= g->second){
                // printf("SITUATION 1\n");
                ll val = g->second;
                to_del_give.pb(mp(g,i));
                to_del_take.pb(mp(take[g->first].find(i),g->first));
                give[t->first][g->first]+=val;
                take[g->first][t->first]+=val;
                if(t->second == g->second){
                    to_del_take.pb(mp(t,i));
                    to_del_give.pb(mp(give[t->first].find(i),t->first));
                    t++;
                }else{
                    give[t->first][i]-=val;
                    take[i][t->first]-=val;
                    t->second-=val;
                }
                g++;
            }
            else{
                ll val = t->second;
                g->second-=val;
                give[t->first][g->first]+=val;
                take[g->first][t->first]+=val;
                take[g->first][i]-=val;
                to_del_take.pb(mp(t,i));
                to_del_give.pb(mp(give[t->first].find(i),t->first));
                t++;
            }
           }
       }
       for(auto k: to_del_take){
           take[k.second].erase(k.first);
       }
       for(auto k: to_del_give){
           give[k.second].erase(k.first);
       }
    //    printMap();
   }
   V<P<int,P<int,ll>>> ans;
   loop(i,0,n){
       for(auto k: give[i]){
         ans.pb(mp(i+1,mp(k.first+1,k.second)));
       }
   }
   cout << ans.size() << "\n";
   for(auto i: ans){
       cout << i.F << " " << i.S.F << " " << i.S.S << "\n";
   }
   return 0;
}
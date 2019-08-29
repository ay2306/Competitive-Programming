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
class EnergySource{
    V<int> divi[100];
    public:
    EnergySource(){
        
    }
    V<ll> countDifferentSources(int number){
        for(int i = 1; i <= 90; ++i){
            for(int j = 2; j <= i; ++i){
                if(i%j == 0){
                    divi[i].pb(j);
                }
            }
        }
        queue<map<int,int> > que;
        set<map<int,int> > st;
        map<int,int> mp;
        mp[number] = 1;
        que.push(mp);
        st.insert(mp);
        while(!que.empty()){
            mp = que.front();
            que.pop();
            for(auto p: mp){
                int value = p.first;
                int num = p.second;
                if(num == 0)continue;
                for(auto d: divi[value]){
                    if(d == 1)continue;
                    auto mp2 = mp;
                    mp2[value]--;
                    if(mp2[value] == 0)mp2.erase(value);
                    mp2[value/d]+=d;

                    if(st.count(mp2))continue;
                    st.insert(mp2);
                    que.push(mp2);
                }
            }
        }
        ll A = st.size();
        ll B = 0;
        for(const auto& s: st){
            ll b = 1;
            for(const auto& p: s){
                if(p.first == 0)continue;
                for(int i = 0; i < p.second; ++i){
                    b*=p.first;
                }
            }
            B+=b;
        }
        return vector<ll> {A,B};
    }
};
int main(){

    return 0;
}
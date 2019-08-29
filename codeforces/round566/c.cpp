/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

bool isV(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
    return false;
}

int main(){
    FAST
    int n;
    cin >> n;
    vector<pair<pair<string,string>,pair<string,string>>> ans;
    map<pair<char,int>,vector<string>> m;
    loop(i,0,n){
        string a;
        cin >> a;
        int ct = 0;
        char lst = 'a';
        for(auto &i: a){
            if(isV(i)){
                ct++;
                lst = i;
            }
        }
        m[mp(lst,ct)].pb(a);
    }
    unordered_map<int,V<string>> rem;
    for(auto it = m.begin(); it != m.end(); ++it){
        if(it->second.size() % 2 == 1){
            rem[it->first.second].pb(it->second.back());
            it->second.pop_back();
        }
    }
    while(1){
        if(m.size() == 0)break;
        auto it = m.begin();
        if(it->second.size() < 2){
            if(it->second.size() == 1){
                rem[it->first.second].pb(it->second.back());
            }
            m.erase(it);
            if(m.size() == 0)break;
            continue;
        }
        string b = it->second.back();
        it->second.pop_back();
        string d = it->second.back();
        it->second.pop_back();
        bool f = false;
        string a;
        string c;
        if(rem.size()){
            stack<unordered_map<int,V<string>>::iterator> s;
            for(auto it1 = rem.begin(); it1 != rem.end(); ++it1){
                if(it1->second.size() > 1){
                    a = it1->second.back();
                    it1->second.pop_back();
                    c = it1->second.back();
                    it1->second.pop_back();
                    f = true;
                    break;
                }
                s.push(it1);
            }
            while(s.size()){
                rem.erase(s.top());
                s.pop();
            }
        }
        if(f){
            ans.pb(mp(mp(a,b),mp(c,d)));
        }else{
            if(it->second.size() > 1){
                string a = it->second.back();
                it->second.pop_back();
                string c = it->second.back();
                it->second.pop_back();
                ans.pb(mp(mp(a,b),mp(c,d)));
                f = true;
            }
            if(!f){
                auto it1 = it;
                it1++;
                while(it1 != m.end()){
                    if(it1->second.size() > 1){
                        a = it1->second.back();
                        it1->second.pop_back();
                        c = it1->second.back();
                        it1->second.pop_back();
                        f = true;
                        ans.pb(mp(mp(a,b),mp(c,d)));
                        break;
                    }
                    it1++;
                }
            }
        }
        if(!f){
            for(auto &i: it->second){
                rem[it->first.second].pb(i);
            }
            m.erase(it);
        }else{
            if(it->second.size() == 1){
                rem[it->first.second].pb(it->second.back());
            }
            if(it->second.size() < 2)m.erase(it);
        }
    }
    cout << ans.size() << "\n";
    for(auto &i: ans){
        cout << i.F.F << " " << i.F.S << "\n" << i.S.F << " " << i.S.S << "\n";
    }
    return 0;
}
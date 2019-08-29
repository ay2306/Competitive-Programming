#include <bits/stdc++.h>
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
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        V<P<P<int,int>,string> > v;
        char a;
        while(q--){
        cin >> a;
            if(a == 'a'){
            string s;
            int x,y;
            cin >> s >> x >> y;
            v.pb(mp(mp(x,y),s));
        }
        if(a == 'b'){
            cout << v.size() << " ";
        }
        if(a == 'd'){
            sort(v.begin(),v.end());
        }
        if(a == 'c'){
            for(int i = 0; i < v.size(); ++i){
                cout << v[i].second << " " << v[i].first.first << " " << v[i].first.second << " ";
            }
        }
        }
        cout << endl;
    }
    return 0;
}
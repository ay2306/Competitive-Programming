#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
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
#define PII pair<pair<int,int>, bool>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    P<ll,ll> *a;
    P<ll,ll> *b;
    int ans;
    // cin >> n >> m;
    a = new P<ll,ll>[n];
    b = new P<ll,ll>[m];
    V<P<ll,ll> > va,vb;
    for(int i = 0; i < n; ++i){
        ll e,f;
        cin >> e >> f;
        a[i] = mp(e,f);
    }
    for(int i = 0; i < m; ++i){
        ll e,f;
        cin >> e >> f;
        b[i] = mp(e,f);
    }
    for(int i = 0; i < n; ++i){
        bool p = true;
        bool r = false;
        for(int j = 0; j < m; ++j){
            if(a[i].first == b[j].first && a[i].second != b[j].second){
                r = true;
                // va.pb(a[i]);
            }
            if(a[i].first != b[j].first && a[i].second == b[j].second){
                r = true;
                // va.pb(a[i]);
            }
            if(a[i].first == b[j].first && a[i].second == b[j].second){
                p = false;
                // va.pb(a[i]);
            }

        }
        if(p && r)va.pb(a[i]);
    }
    for(int i = 0; i < m; ++i){
        bool p = true;
        bool r = false;
        for(int j = 0; j < n; ++j){
            if(b[i].first == a[j].first && b[i].second != a[j].second){
                r = true;
                // vb.pb(b[i]);
            }
            if(b[i].first != a[j].first && b[i].second == a[j].second){
                r = true;
                // vb.pb(b[i]);
            }
            if(b[i].first != a[j].first && b[i].second == a[j].second){
                p = false;
                // vb.pb(b[i]);
            }
        }
        if(p && r)vb.pb(b[i]);
    }
    ans = 0;
    cout << va.size() << " " << vb.size() << endl;
    if(va.size() == 1 && vb.size() == 1){
        ans = 1;
    }
    for(int i = 0; i < m; ++i){
        bool f = false;
        bool s = false;
        for(int j = 0; j < n; ++j){
            if(b[i].first == a[j].first && b[i].second != a[j].second){
                // vb.pb(b[i]);
                f == true;
            }
            else if(b[i].first != a[j].first && b[i].second == a[j].second){
                s = true;
            }
        }
        if(s && f){
            ans = -1;
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        bool f = false;
        bool s = false;
        for(int j = 0; j < m; ++j){
            if((a[i].first == b[j].first && a[i].second != b[j].second) || (a[i].first == b[j].second && a[i].second != b[j].first)){
                // vb.pb(b[i]);
                f == true;
            }
            else if((a[i].first != b[j].first && a[i].second == b[j].second) || (a[i].first != b[j].second && a[i].second == b[j].first)){
                s = true;
            }
        }
        if(s && f){
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}
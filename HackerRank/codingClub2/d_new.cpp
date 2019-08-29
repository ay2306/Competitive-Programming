#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[200100],b[200100];

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,q;
    cin >> n >> q;
    for(ll i = 0; i < n; ++i){
        if(i%2){
            cin >> b[i];
        }else{
            cin >> a[i];
        }
    }
    while(q--){
        char c;
        ll e,f;
        cin >> c;
        if(c == 'u'){
            cin >> e >> f;
            e--;
            if(e%2)b[e]=f;
            else a[e] = f;
        }else if(c == 'q'){
            cin >> e >> f;
            e--;
            f--;
            ll size = e-f+1;
            if(size%2 == 0){
                cout << "0\n";
                continue;
            }
            ll ans = 0;
            if(e%2){
                for(ll i = e; i <= f; ++i)ans^=b[i];
            }else{
                for(ll i = e; i <= f; ++i)ans^=a[i];    
            }
            cout << ans << endl;
        }
    }
    return 0;
}
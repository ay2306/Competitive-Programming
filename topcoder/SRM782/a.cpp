#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class GoblinRabblemaster{
public:
    ll totalDamage(int T){
        ll normal = 0;
        ll special = 0;
        ll ans = 0;
        for(int i = 1; i <= T; ++i){
            normal+=special;
            normal++;
            ans+=(normal);
            ans+=(special*(special+1+normal));
            special++;
            cout << ans << "\n";
        }
        return ans;
    }
};

int main(){
    GoblinRabblemaster a;
    int k ;
    cin >> k;
    cout << a.totalDamage(k);
}
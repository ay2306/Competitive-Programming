#include<iostream>
using namespace std;

const int inf = 1e9;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mn,ans = 0;
        cin >> mn;
        for(int i = 1; i < n; ++i){
            int a;
            cin >> a;
            ans = max(ans,a-mn);
            mn = min(a,mn);
        }
        if(ans > 0)cout << ans << "\n";
        else cout << "UNFIT\n";
    }
    return 0;
}
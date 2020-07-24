#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int a = 0;
            cin >> a;
            if(a & 1)ans++;
            else if(x)ans++,x--;
        }
        cout << ans << "\n";
    }
    return 0;
}
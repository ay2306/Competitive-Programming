#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0,a;
    while(n--){
        cin >> a;
        ans = __gcd(ans,a);
    }
    cout << ans;
    return 0;
}
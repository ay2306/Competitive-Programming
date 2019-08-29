#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int val = 0;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            val = __gcd(val,a);
        }
        cout << ((val == 1)?n:-1) << "\n";
    }
    return 0;
}
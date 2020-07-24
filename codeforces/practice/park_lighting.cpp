#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a % 2 == 0 || b % 2 == 0){
            cout << a*b/2 << "\n";
        }else{
            cout << min(((a-1)*b)/2 + b/2 +1,((b-1)*a)/2 + a/2 +1) << "\n";
        }
    }
    return 0;
}
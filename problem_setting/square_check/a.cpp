#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,n,v=1;
        cin >> n;
        while(n--){
            cin >> a;
            if(a < 0 || (int)sqrt(a) * (int)sqrt(a) != a)v=0;
        }
        v ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}